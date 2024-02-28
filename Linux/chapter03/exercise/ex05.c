#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int filedes;
    char buffer[1024];
    ssize_t nread;
    off_t newpos;

    if ((filedes = open("./temp0.txt", O_RDONLY)) < 0) {
        perror("파일 열기 실패");
        exit(1);
    }

    if ((newpos = lseek(filedes, (off_t) 0, SEEK_CUR)) == (off_t) - 1) {
        perror("읽기/쓰기 포인터 이동 실패");
        exit(1);
    }
    printf("읽기/쓰기 포인터 위치: %ld\n", newpos);

    while ((nread = read(filedes, buffer, sizeof(buffer) - 1)) > 0) {
        printf("읽은 바이트 수: %zu\n", nread);
        puts(buffer);
    }

    if ((newpos = lseek(filedes, (off_t) 0, SEEK_CUR)) == (off_t) - 1) {
        perror("읽기/쓰기 포인터 이동 실패");
        exit(1);
    }
    printf("읽기/쓰기 포인터 위치: %ld\n", newpos);

    close(filedes);

    return 0;
}
