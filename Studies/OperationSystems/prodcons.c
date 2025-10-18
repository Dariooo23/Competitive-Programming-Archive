#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

/***
 * (i) Dokończyć implementację struktury buffer_t oraz metod insert i get aby wykorzystywały semafory.
 *     Celem jest implementacja kolejki FIFO: producenci dokładają elementy a konsumenci je pobierają.
 *     Podpowiedź: przyda się więcej niż jeden semafor.
 *
 * (ii)* Proszę zmodyfikować producenta aby produkował zestawy paczek, tj. np.
 * `2, 3, 1`
 * to zestaw trzech kolejnych paczek, gdzie pierwsza wartość do ilość kolejnych paczek w zestawie,
 * a pozostałe dwie paczki to jakieś dane (ich wartość jest ignorowana).
 * Więcej przykładów:
 * `0`
 * `1, 5423478`
 * `3, 2432435345, 0, 2`
 * itd.
 * Należy też zmodyfikować konsumenta aby ten pobierał cały zestaw na raz.
 *
 * Jak należy synchronizować wątki aby nie dopuścić do zagłodzenia?
 */

#define BSIZE 20

typedef struct {
    int buf[BSIZE];
    int head, tail;
    int count;
    sem_t empty;
    sem_t full;
    sem_t mutex; // Semafor do ochrony zapisu/odczytu bufora
} buffer_t;

buffer_t g_monitor;

void print_buffer(const char *who) {
    printf("%s, licznik = %02d, buf [", who, g_monitor.count);

    for (int i = 0; i < BSIZE; i++) {
        int rel = (i - g_monitor.tail + BSIZE) % BSIZE;
        if (rel < g_monitor.count)
            printf("%3d ", g_monitor.buf[i]);
        else
            printf("    ");
    }

    printf("]\n");
    return;
}

void insert(int no) {
    // Produkcja zestawu zlozonego z kilku paczek (poza mutexem)
    sem_wait(&g_monitor.empty);
    int cnt = rand() % 6;
    int *set = malloc((cnt + 1) * sizeof(int));
    set[0] = cnt;

    for (int i = 1; i <= cnt; i++) {
        set[i] = rand() % 1000;
    }

    // Zapisanie zestawu paczek (Chronione mutexem | Sekcja krytyczna)
    sem_wait(&g_monitor.mutex);

    for (int i = 0; i <= cnt; i++) {
        g_monitor.buf[g_monitor.head] = set[i];
        g_monitor.head = (g_monitor.head + 1) % BSIZE;
        g_monitor.count++;
    }

    char who[16];
    snprintf(who, sizeof(who), "PROD %d", no);
    print_buffer(who);

    sem_post(&g_monitor.mutex);
    // Koniec zapisu zestawu paczek (Chronione mutexem | Sekcja krytyczna)

    sem_post(&g_monitor.full);
    free(set);
    return;
}

void get(int no) {
    sem_wait(&g_monitor.full);

    // Pobranie zestawu paczek (Chronione mutexem | Sekcja krytyczna)
    sem_wait(&g_monitor.mutex);

    int cnt = g_monitor.buf[g_monitor.tail];
    g_monitor.tail = (g_monitor.tail + 1) % BSIZE;
    g_monitor.count--;

    int *set = malloc((cnt + 1) * sizeof(int));
    set[0] = cnt;

    for (int i = 1; i <= cnt; i++) {
        set[i] = g_monitor.buf[g_monitor.tail];
        g_monitor.tail = (g_monitor.tail + 1) % BSIZE;
        g_monitor.count--;
    }

    char who[16];
    snprintf(who, sizeof(who), "KONS %d", no);
    print_buffer(who);

    sem_post(&g_monitor.mutex);
    //Koniec pobierania zestawu paczek (Chronione mutexem | Sekcja krytyczna)

    //Ewentualne przetwarzanie zestawu paczek (poza mutexem)
    free(set);
    sem_post(&g_monitor.empty);
    return;
}


void *producer(void *nr){
    int no = *((int *) nr);
    for(int j = 0; j < 100; j++) {insert(no); sleep(1);}
    pthread_exit(0);
}

void *consumer(void *nr){
    int no = *((int *) nr);
    for(int j = 0; j < 100; j++) {get(no); sleep(rand() % 10);}
    pthread_exit(0);
}

int main() {
    pthread_t prod[5], kons[5];
    int ids[5];

    g_monitor.head = g_monitor.tail = g_monitor.count = 0;

    sem_init(&g_monitor.empty, 0, BSIZE / 6); //Zestawy maja maksymalnie 5 paczek + 1 na informacje o ilosci paczek
    sem_init(&g_monitor.full, 0, 0);
    sem_init(&g_monitor.mutex, 0, 1);

    for (int i = 0; i < 5; i++) {
        ids[i] = i;
        pthread_create(&prod[i], NULL, producer, &ids[i]);
        pthread_create(&kons[i], NULL, consumer, &ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(prod[i], NULL);
        pthread_join(kons[i], NULL);
    }

    return 0;
}
