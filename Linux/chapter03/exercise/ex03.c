#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    int filedes;
    const char *newmsg = "NEW MESSAGE REWRITE\n";

    if ((filedes = open("./ex03.txt", O_WRONLY)) < 0) {
        fprintf(stderr, "파일 열기 실패\n");
        exit(1);
    }

    if ((write(filedes, newmsg, strlen(newmsg))) != strlen(newmsg)) {
        fprintf(stderr, "파일 덮어쓰기 중 오류 발생\n");
        exit(1);
    }

    close(filedes);
    puts("파일 덮어쓰기 완료");

    return 0;
}
