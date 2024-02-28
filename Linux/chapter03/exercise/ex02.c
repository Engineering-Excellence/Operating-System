#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    const char *relpath = "./temp0.txt";
    int filedes;
    ssize_t nwrite;
    const char *msg = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nDonec.\n";

    if ((filedes = open(relpath, O_CREAT | O_TRUNC | O_RDWR, 0644)) < 0) {
        fprintf(stderr, "파일 생성 오류\n");
        exit(1);
    }
    printf("filedes=%d\n", filedes);

    if ((nwrite = write(filedes, msg, strlen(msg))) != strlen(msg)) {
        fprintf(stderr, "파일 쓰기 오류\n");
        exit(1);
    }
    printf("쓰기 바이트: %zd\n", nwrite);

    close(filedes);
    puts("파일 생성 완료");

    return 0;
}
