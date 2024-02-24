//#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void) {
    int filedes;
    off_t newpos;

    filedes = open("data1.txt", O_RDONLY);

    /* 읽기/쓰기 포인터를 EOF로 이동한다. */
    newpos = lseek(filedes, (off_t) 0, SEEK_END);
    printf("file size: %ld\n", newpos);

    return 0;
}
