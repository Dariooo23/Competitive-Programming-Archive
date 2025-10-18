// Systemy Operacyjne, Laboratorium 2025
// Uniwersytet Jagielloński w Krakowie
// Piotr Bartman-Szwarc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>



/**
 * Zaimplementować program który realizuje polecenia przy pomocy pipe'ów i procesów potomnych:
 *
 * (i) ps – ef | grep <user name>
 *
 * (ii) ps –ef | grep <user name> | wc –l
 *
 * (iii) cat /etc/group | head -5 > grupy.txt
 *
 *
 */



 void ps_grep(const char *username) {
    int pipe1[2];
    if (pipe(pipe1) == -1) {
        fprintf(stderr, "ps_grep: Pipe function execution error\n");
        exit(1);
    }

    if (fork() == 0) {
        close(pipe1[0]);
        if (dup2(pipe1[1], 1) == -1) {
            fprintf(stderr, "ps_grep: Ps Dup2 function execution error\n");
            exit(1);
        }
        close(pipe1[1]);

        execlp("ps", "ps", "-ef", NULL);

        fprintf(stderr, "ps_grep: Execlp ps function execution error\n");
        exit(1);
    }

    if (fork() == 0) {
        close(pipe1[1]);
        if (dup2(pipe1[0], 0) == -1) {
            fprintf(stderr, "ps_grep: Grep Dup2 function execution error\n");
            exit(1);
        }
        close(pipe1[0]);

        execlp("grep", "grep", username, NULL);
        
        fprintf(stderr, "ps_grep: Execlp grep function execution error\n");
        exit(1);
    }

    close(pipe1[0]);
    close(pipe1[1]);

    wait(NULL);
    wait(NULL);

    return;
}



void ps_grep_wc(char *user_name) {
    int pipe1[2], pipe2[2];

    if (pipe(pipe1) == -1) {
        fprintf(stderr, "ps_grep_wc: Pipe 1 function execution error\n");
        exit(1);
    }

    if (pipe(pipe2) == -1) {
        fprintf(stderr, "ps_grep_wc: Pipe 2 function execution error\n");
        exit(1);
    }

    if (fork() == 0) {
        close(pipe1[0]);
        if (dup2(pipe1[1], 1) == -1) {
            fprintf(stderr, "ps_grep_wc: Ps Dup2 function execution error\n");
            exit(1);
        }
        close(pipe1[1]);

        execlp("ps", "ps", "-ef", NULL);

        fprintf(stderr, "ps_grep_wc: Execlp ps function execution error\n");
        exit(1);
    }

    if (fork() == 0) {
        close(pipe1[1]);
        if (dup2(pipe1[0], 0) == -1) {
            fprintf(stderr, "ps_grep_wc: Grep Dup2 function execution error\n");
            exit(1);
        }
        close(pipe1[0]);  
        close(pipe2[0]);  
        if (dup2(pipe2[1], 1) == -1) {
            fprintf(stderr, "ps_grep_wc: Grep Dup2 function execution error\n");
            exit(1);
        }
        close(pipe2[1]);

        execlp("grep", "grep", user_name, NULL); 

        fprintf(stderr, "ps_grep_wc: Execlp grep function execution error\n");
        exit(1);
    }

    if (fork() == 0) {
        close(pipe2[1]);
        if (dup2(pipe2[0], 0) == -1) {
            fprintf(stderr, "ps_grep_wc: Wc Dup2 function execution error\n");
            exit(1);
        }
        close(pipe2[0]);

        execlp("wc", "wc", "-l", NULL);

        fprintf(stderr, "ps_grep_wc: Execlp wc function execution error\n");
        exit(1);
    }

    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);

    wait(NULL);
    wait(NULL);
    wait(NULL);

    return;
}



void cat_head_to_file() {
    int fd = open("grupy.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0) {
        fprintf(stderr, "cat_head_to_file: Error creating output file\n");
        exit(1);
    }

    int pipe1[2];
    if (pipe(pipe1) == -1) {
        fprintf(stderr, "cat_head_to_file: Pipe function execution error\n");
        exit(1);
    }

    if (fork() == 0) { 
        close(pipe1[0]);
        if (dup2(pipe1[1], 1) == -1) {
            fprintf(stderr, "cat_head_to_file: Cat Dup2 function execution error\n");
            exit(1);
        }
        close(pipe1[1]);

        execlp("cat", "cat", "/etc/group", NULL);

        fprintf(stderr, "cat_head_to_file: Execlp cat function execution error\n");
        exit(1);
    }

    if (fork() == 0) {
        close(pipe1[1]);
        if (dup2(pipe1[0], 0) == -1) {
            fprintf(stderr, "cat_head_to_file: Head Dup2 function execution error\n");
            exit(1);
        }
        close(pipe1[0]);
        if (dup2(fd, 1) == -1) {
            fprintf(stderr, "cat_head_to_file: Head Dup2 function execution error\n");
            exit(1);
        }
        close(fd);

        execlp("head", "head", "-5", NULL);

        fprintf(stderr, "cat_head_to_file: Execlp head function execution error\n");
        exit(1);
    }

    close(pipe1[0]);
    close(pipe1[1]);
    close(fd);

    wait(NULL);
    wait(NULL);

    return;
}



int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Too few args\n");
        return 1;
    }

    
    ps_grep(argv[1]);
    printf("------------------\n");
    ps_grep_wc(argv[1]);
    printf("------------------\n");
    cat_head_to_file();

    return 0;
}
