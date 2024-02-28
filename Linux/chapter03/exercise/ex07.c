#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    int filedes;
    char buffer[2];
    int cnt = 0;

    if ((filedes = open("./data.txt", O_RDONLY)) < 0) {
        perror("파일 열기 실패");
        exit(1);
    }

    while ((read(filedes, buffer, sizeof(buffer) - 1)) > 0) {
        if (isalpha(buffer[0])) cnt++;
    }

    printf("알파벳의 개수: %d개\n", cnt);

    close(filedes);

    return 0;
}
