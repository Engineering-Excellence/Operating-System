#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    if (chown("test.txt", 1000, 1000) == -1) {
        perror("파일 소유자 변경 불가");
        exit(1);
    } else {
        puts("파일 소유자 변경 완료");
    }

    return 0;
}
