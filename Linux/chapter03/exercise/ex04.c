#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int filedes;
    off_t newpos;

    if ((filedes = open("./temp0.txt", O_RDONLY)) < 0) {
        perror("파일 열기 실패");
        exit(1);
    }

    if ((newpos = lseek(filedes, (off_t) 0, SEEK_END)) == (off_t) - 1) {
        perror("읽기/쓰기 포인터 이동 실패");
        exit(1);
    }
    printf("읽기/쓰기 포인터 위치: %ld\n", newpos);

    if ((newpos = lseek(filedes, (off_t) 10, SEEK_CUR)) == (off_t) - 1) {
        perror("읽기/쓰기 포인터 이동 실패");
        printf("읽기/쓰기 포인터 위치: %ld\n", newpos);
        exit(1);
    }
    printf("읽기/쓰기 포인터 위치: %ld\n", newpos);

    close(filedes);

    return 0;
}
