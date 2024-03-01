#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int filedes;

    if ((filedes = open("test.txt", O_RDWR)) == -1) {
        perror("파일 개방 실패");
        exit(1);
    }
    printf("%d\n", filedes);
    close(filedes);

    return 0;
}
