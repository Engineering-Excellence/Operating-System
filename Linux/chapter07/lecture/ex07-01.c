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

    if (pid > 0) {  // fork를 호출 성공한 부모 프로세스가 수행
        for (; i < 7; ++i) {
            printf("parent [%d]\n", i);
            sleep(1);
        }
        atexit(cleanupaction);
    } else if (pid == 0) {  // 자식 프로세스가 수행
        for (; i < 5; ++i) {
            printf("child [%d]\n", i);
            sleep(1);
            execl("/bin/ls", "ls", "-ail", (char *) 0);
        }
    } else {
        perror("fail to fork child process\n"); // pid == -1
    }

    exit(0);
}

void cleanupaction(void) {
    puts("clean-up-action");
}
