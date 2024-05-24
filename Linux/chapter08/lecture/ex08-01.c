#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    pid_t pid;
    int status;

    pid = fork();   // 자식 프로세스 생성

    putenv("APPLE=RED");    // 환경변수 등록, 환경 변수명: APPLE, 값: RED

    if (pid > 0) {  // 부모 프로세스 실행
        printf("[parent] PID: %d\n", getpid()); // 부모 프로세스 식별번호
        printf("[parent] PPID: %d\n", getppid());   // 셸(부모의 부모) 프로세스 식별번호
        printf("[parent] GID: %d\n", getpgrp());    // 부모 그룹 식별번호
        printf("[parent] SID: %d\n", getsid(0));    // 부모 세션 식별번호

        waitpid(pid, &status, 0);   // 자식 프로세스 종료시까지 대기

        printf("[parent] status is %d\n", status);  // 자식 프로세스가 전달한 종료 상태값을 출력

        unsetenv("APPLE");  // 환경변수 삭제
    } else if (pid == 0) {  // 자식 프로세스 실행
        printf("[child] PID: %d\n", getpid());  // 자식 프로세스 식별번호
        printf("[child] PPID: %d\n", getppid());    // 부모 프로세스 식별번호
        printf("[child] GID: %d\n", getpgid(0));    // 부모 그룹 식별번호
        printf("[child] SID: %d\n", getsid(0)); // 부모 세션 식별번호

        sleep(1);

        printf("[child] APPLE=%s\n", getenv("APPLE"));  // 환경변수 출력

        exit(1);
    } else {
        puts("fail to fork");
    }

    return 0;
}