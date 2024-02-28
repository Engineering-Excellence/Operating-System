#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int filedes;
    const char *path = "./ex10.txt";
    const char *msg = "MODIFIED";

    if ((filedes = open(path, O_WRONLY)) == -1) {   // 파일 열기
        perror("파일 열기 실패");
        exit(1);
    }

    if (write(filedes, msg, strlen(msg)) != strlen(msg)) {  // 파일 내용 변경
        perror("파일 덮어쓰기 실패");
        exit(1);
    }

    puts("파일을 닫지 않고 대기합니다.");
    pause();    // 파일을 닫지 않고 대기

    return 0;
}
