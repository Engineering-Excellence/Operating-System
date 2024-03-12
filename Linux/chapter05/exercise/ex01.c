#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        perror("파라미터 개수가 잘못 입력되었습니다.");
        exit(1);
    }

    printf("디렉터리 경로가 %s.\n", access(argv[1], F_OK) == 0 ? "존재합니다" : "존재하지 않습니다");

    return 0;
}
