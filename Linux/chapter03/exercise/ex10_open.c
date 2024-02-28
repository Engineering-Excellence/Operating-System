#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int filedes;
    const char *path = "./ex10.txt";
    char buffer[1024];

    if ((filedes = open(path, O_RDONLY)) == -1) {
        perror("파일 열기 실패");
        exit(1);
    }

    if (read(filedes, buffer, sizeof(buffer) - 1) == -1) {
        perror("파일 읽기 실패");
        exit(1);
    }

    puts(buffer);

    close(filedes);

    return 0;
}
