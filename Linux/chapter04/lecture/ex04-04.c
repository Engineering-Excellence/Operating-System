#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    const char *filename = "test.txt";

    if (access(filename, R_OK) == -1) { // 읽기 권한 여부 검사
        fprintf(stderr, "%s 파일 읽기 권한이 없습니다.\n", filename);
        exit(1);
    } else {
        printf("%s 읽기 가능\n", filename);
    }

    return 0;
}
