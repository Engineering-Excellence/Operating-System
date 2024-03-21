#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void cleanupaction(void);

int main(void) {
    pid_t pid;
    int i;

    for (i = 0; i < 3; ++i) {
        printf("before fork [%d]\n", i);
        sleep(1);
    }

    pid = fork();

    if (pid > 0) {
        for (; i < 7; ++i) {
            printf("parent [%d]\n", i);
            sleep(1);
        }
        atexit(cleanupaction);
    } else if (pid == 0) {
        for (; i < 5; ++i) {
            printf("child [%d]\n", i);
            sleep(1);
            execl("/bin/ls", "ls", "-ail", (char *) 0);
        }
    } else {
        perror("fail to fork child process\n");
    }

    exit(0);
}

void cleanupaction(void) {
    puts("clean-up-action");
}
