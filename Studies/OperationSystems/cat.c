// Systemy Operacyjne, Laboratorium 2025
// Uniwersytet Jagielloński w Krakowie
// Piotr Bartman-Szwarc

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * 1. Zaimplementować funkcję `my_cat` imitującą działanie komendy
 *    `cat` w bashu łączącej n>=1 plików w jeden tj.
 *    `./exc02 output_file input_file_1 input_file_2`
 *    Zapisze do pliku output_file:
 *    ```
 *    //input_file_1:
 *    <zawartość input_file_1>//input_file_2:
 *    <zawartość input_file_2>
 *    ```
 *
 * @param argc number of arguments + 1
 * @param argv name of program + arguments
 * @return 1 if error else 0
 */

#define BUFFER_SIZE 1024
#define NAME_OF_PROGRAM 0
#define OUTPUT 1
#define FIRST_FILE 2

int my_cat(int argc, char *argv[]) {
    char buf[BUFFER_SIZE];
    if (argc < FIRST_FILE + 1) {
        fprintf(stderr, "Too few args!\n");
        return 1;
    }



    int temp_fd = creat(argv[OUTPUT], 0644);
    if (temp_fd == -1) {
        fprintf(stderr, "Error creating output file!\n");
        return 1;
    }

    int output_fd = open(argv[OUTPUT], O_WRONLY);
    if (output_fd == -1) {
        fprintf(stderr, "Error opening output file!\n");
        return 1;
    }



    for (int i = FIRST_FILE; i < argc; i++) {
        int input_fd = open(argv[i], O_RDONLY);
        if (input_fd == -1) {
            fprintf(stderr, "Error opening input file!\n");
            close(output_fd);
            return 1;
        }

        if (write(output_fd, "//", 2) == -1){
            fprintf(stderr, "Error writing to output file!\n");
            close(input_fd);
            close(output_fd);
            return 1;
        }
        if (write(output_fd, argv[i], strlen(argv[i])) == -1){
            fprintf(stderr, "Error writing to output file!\n");
            close(input_fd);
            close(output_fd);
            return 1;
        }
        if (write(output_fd, ":\n", 2) == -1){
            fprintf(stderr, "Error writing to output file!\n");
            close(input_fd);
            close(output_fd);
            return 1;
        }
        
        int bytes_read;
        while ((bytes_read = read(input_fd, buf, BUFFER_SIZE)) > 0) {
            if (write(output_fd, buf, bytes_read) != bytes_read) {
                fprintf(stderr, "Error writing to output file!\n");
                close(input_fd);
                close(output_fd);
                return 1;
            }
        }

        if (bytes_read == -1) {
            fprintf(stderr, "Error reading input file!\n");
            close(input_fd);
            close(output_fd);
            return 1;
        }

        close(input_fd);
    }

    close(output_fd);
    return 0;
}

int main(int argc, char *argv[]) {
    return my_cat(argc, argv);
}