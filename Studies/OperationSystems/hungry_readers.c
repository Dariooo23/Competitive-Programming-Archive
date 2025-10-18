//rozwiazanie z zaglodzeniem czytelnikow
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define L_PISARZY 10
#define L_CZYTELNIKOW 10
#define TIME 3

pthread_t pisarze[L_PISARZY];           //tablica watkow pisarzy
pthread_t czytelnicy[L_CZYTELNIKOW];    //tablica watkow czytelnikow
sem_t mozna_czytac;                     //1 - sa wolne miejsca dla czytelnikow
sem_t mozna_pisac;                      //1 - jest wolne miejsce dla pisarza
sem_t poczekalnia_czytelnikow;
sem_t poczekalnia_pisarzy;
//sem_t sprobuj_czytac;
int lc = 0;                             //liczba czytelnikow w bibliotece
int lp = 0;                             //liczba pisarzy w bibliotece


void *pisarz(void *arg) {
    int num = *((int *) arg);
    while (1) {
        printf("Pisarz %d czeka...\n", num);

        sem_wait(&poczekalnia_pisarzy);
        
        lp++;
        if (lp == 1){
            sem_wait(&mozna_czytac);
        }

        sem_post(&poczekalnia_pisarzy);
        sem_wait(&mozna_pisac);

        printf("Pisarz %d pisze...\n", num);
        sleep(rand() % TIME);

        sem_post(&mozna_pisac);
        sem_wait(&poczekalnia_pisarzy);
        
        lp--;
        if (lp == 0){
            sem_post(&mozna_czytac);
        }

        sem_post(&poczekalnia_pisarzy);

        printf("Pisarz %d wychodzi...\n", num);

        sleep(1);
    }
}


void *czytelnik(void *arg) {
    int num = *((int *) arg);
    while (1) {
        printf("Czytelnik %d czeka...\n", num);

        sem_wait(&mozna_czytac);
        sem_wait(&poczekalnia_czytelnikow);

        lc++;
        if (lc == 1){
            sem_wait(&mozna_pisac);
        }

        sem_post(&poczekalnia_czytelnikow);
        sem_post(&mozna_czytac);

        printf("Czytelnik %d czyta...\n", num);
        sleep(rand() % TIME);

        sem_wait(&poczekalnia_czytelnikow);
        lc--;

        if(lc == 0){
            sem_post(&mozna_pisac);
        }

        sem_post(&poczekalnia_czytelnikow);

        printf("Czytelnik %d wychodzi...\n", num);
    }
}


int main() {
    int num_pis[L_PISARZY] = {0};
    int num_czy[L_CZYTELNIKOW] = {0};

    sem_init(&poczekalnia_czytelnikow, 0, 1);
    sem_init(&poczekalnia_pisarzy, 0, 1);

    sem_init(&mozna_czytac, 0, 1);
    sem_init(&mozna_pisac, 0, 1);

    for (int i = 0; i < L_PISARZY; i++) {       //tworzenie watkow pisarzy
        num_pis[i] = i;
        pthread_create(&pisarze[i], NULL, &pisarz, &num_pis[i]);
    }
    for (int i = 0; i < L_CZYTELNIKOW; i++) {   //tworzenie watkow czytelnikow
        num_czy[i] = i;
        pthread_create(&czytelnicy[i], NULL, &czytelnik, &num_czy[i]);
    }
    for (int i = 0; i < L_PISARZY; i++)
        pthread_join(pisarze[i], NULL);             //oczekiwanie az wszyscy pisarze wroca z czytelni
    for (int i = 0; i < L_CZYTELNIKOW; i++)
        pthread_join(czytelnicy[i], NULL);      //oczekiwanie az wszyscy czytelnicy wroca z czytelni
}

