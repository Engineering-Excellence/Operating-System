#include <unistd.h>
#include <stdio.h>

int main(void) {
    pid_t pid;

    puts("Hello!");

    pid = fork();   // 부모 프로세스의 복사본 생성

    if (pid > 0) {  // fork를 호출한 부모 프로세스가 수행
        puts("Parent Process");
        sleep(1);
    } else if (pid == 0) {  // 자식 프로세스가 수행
        puts("Child Process");
        execl("/bin/ls", "ls", "-l", (char *) 0);
        perror("Fail to execute ls\n"); // execl을 실행한 프로세스(자식)는 종료되므로 실행되지 않음
    } else {    // pid == -1
        perror("Parent: Fail to fork\n");
    }

    puts("Bye!");

    return 0;
}
