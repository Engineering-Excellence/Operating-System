#include <unistd.h>
#include <stdio.h>

int main(void) {
    pid_t pid;
    int i = 0;

    i++;
    printf("Before calling fork(%d)\n", i);

    pid = fork();   // fork 호출 성공시 자식 프로세스 생성

    if (pid == 0)   // 자식 프로세스가 수행할 부분
        printf("Child process(%d)\n", ++i);
    else if (pid > 0)  // 부모 프로세스가 수행할 부분
        printf("Parent process(%d)\n", --i);
    else    // fork 호출 성공 실패시
        perror("Fail to fork");

    return 0;
}
