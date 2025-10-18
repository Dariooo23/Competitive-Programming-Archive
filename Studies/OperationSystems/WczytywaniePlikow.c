// Systemy Operacyjne, Laboratorium 2025
// Uniwersytet Jagielloński w Krakowie
// Piotr Bartman-Szwarc


// W zasadzie wszystkie potrzebne "słowa kluczowe" są tutaj:
#include <stdio.h> // STanDard Input Output: stderr, SEEK_SET, int fprintf(FILE *stream, const char *format, ...), int sprintf(char *str, const char *format, ...)
#include <unistd.h> // UNIx STanDard: write, close, read, lseek
#include <fcntl.h> // File CoNTroL: creat, open, O_RDONLY, O_WRONLY
#include <stdlib.h> // STanDard LIBrary: int rand(...)

/**
* 1. Zaimplementować funkcję `fill_file` tworzącą plik „exc01.output” zawierający
* 666 losowych liczb naturalnych mniejszych od 5000,
* (a) zapisanych w formacie „%4d” tj. każda liczba zajmuje dokładnie 4 miejsca,
* (b) jeżeli liczba jest krótsza to miejsca z lewej uzupełniane są pustym miejscem (spacją),
* (c) jeżeli liczba jest dłuższa wypisywane są liczby najbardziej znaczące.
*
* 2. Zaimplementować funkcję `print_num` wypisującą na stdout n-tą liczbę w pliku.
*/

#define FILE_NAME "exc01.output"
#define NUM 666
#define MAX 5000
#define BUFFER_SIZE 64
#define WORD_SIZE 4

int fill_file() {
char buf[BUFFER_SIZE];
int fd = creat(FILE_NAME, 0644);

if (fd == -1){
return 1;
}

for (int i = 0; i < NUM; i++){
sprintf(buf, "%4d", rand()%MAX);
write(fd, buf, WORD_SIZE);
}

close(fd);
return 0;
}

int print_num(int id) {

int fd = open (FILE_NAME, O_RDONLY);
lseek(fd, id * WORD_SIZE, SEEK_SET);
char buf[BUFFER_SIZE];

int x = read(fd, buf, WORD_SIZE);

if (x < WORD_SIZE){
return 1;
}

printf("%s\n", buf);

close(fd);
return 0;
}

int write_num (int id, int N){
int fd = open (FILE_NAME, O_WRONLY);
lseek(fd, id * WORD_SIZE, SEEK_SET);

char buf[BUFFER_SIZE];

sprintf(buf, "%4d", N);
write(fd, buf, WORD_SIZE);

close(fd);
return 0;
}

int read_4(int fd, int id, char buf[]){
lseek(fd, id * WORD_SIZE, SEEK_SET);

if (read(fd, buf, WORD_SIZE) != WORD_SIZE){
return 1;
}

return 0;
}

int write_4(int fd, int id, char buf[]){
lseek(fd, id * WORD_SIZE, SEEK_SET);

if (write(fd, buf, WORD_SIZE) != WORD_SIZE){
return 1;
}

return 0;
}

int reverse(){
int fd = open(FILE_NAME, O_RDWR);

if (fd == -1){
return 1;
}

char buff_l [BUFFER_SIZE];
char buff_r [BUFFER_SIZE];

for (int i = 0; i < NUM / 2; i++){
read_4(fd, i, buff_l);
read_4(fd, NUM - i - 1, buff_r);
write_4(fd, NUM - i - 1, buff_l);
write_4(fd, i, buff_r);
}

close(fd);
return 0;
}

int main() {
fill_file();
print_num(0);
print_num(NUM - 1);
reverse();
print_num(0);
print_num(NUM - 1);
}
