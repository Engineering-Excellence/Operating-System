#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        perror("인수의 개수가 올바르지 않습니다.");
        exit(1);
    } else if (rename(argv[1], argv[2]) == 0) {
        puts("파일명 변경 성공");
    } else {
        perror("파일명 변경 실패");
    }

    return 0;
}
