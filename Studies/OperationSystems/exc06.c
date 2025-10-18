// Systemy Operacyjne, Laboratorium 2024
// Uniwersytet Jagielloński w Krakowie
// Piotr Bartman-Szwarc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * (i) Zaimplementować program który jako pierwszy parametr przyjmuje ścieżkę do pliku z kodem źródłowym C, kompiluje go
 *     i uruchamia plik wyjściowy.
 *
 * (ii) Umożliwić przekazywanie parametrów.
 *
 * (*) Przekazać stdin, stdout i stderr.
 *
 * (**) Niech program nie pozostawia żadnych nowych plików w folderze, tj. plik wykonywalny powinnien zostać usunięty
 *      po zakończeniu.
 *
 */


int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Too few args!\n");
        return 1;
    }

    char* source_file = argv[1];
    char output_file[] = "./temp_exec";

    int pid;
    int status;

    //Kompilacja pliku źródłowego
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork function execution error\n");
        return 1;
    }

    if (pid == 0) {
        execlp("gcc", "gcc", source_file, "-o", output_file, NULL);
        fprintf(stderr, "Execlp function execution error\n");
        return 1;
    }

    wait(&status);

    if (status != 0) {
        fprintf(stderr, "Compilation error\n");
        return 1;
    }

    //Utworzenie tablicy z argumentami dla pliku wykonywalnego
    char** exec_args = malloc(argc * sizeof(char*));
    if (exec_args == NULL) {
        fprintf(stderr, "Memory allocation error");
        unlink(output_file);
        return 1;
    }  

    exec_args[0] = output_file;
    for (int i = 2; i < argc; i++) {
        exec_args[i - 1] = argv[i];
    }
    exec_args[argc - 1] = NULL;

    //Uruchomienie pliku wykonywalnego
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork function execution error\n");
        unlink(output_file);
        free(exec_args);
        return 1;
    }

    if (pid == 0) {
        execvp(output_file, exec_args);
        fprintf(stderr, "Execvp function execution error\n");
        return 1;
    }

    wait(&status);

    unlink(output_file);
    free(exec_args);

    if (status != 0) {
        fprintf(stderr, "Execution error\n");
        return 1;
    }

    return 0;
}
