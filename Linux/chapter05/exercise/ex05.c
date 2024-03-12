#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    struct stat sb;
    char buffer[FILENAME_MAX];

    if (argc != 2) {
        perror("파라미터 개수가 잘못 입력되었습니다.");
        exit(1);
    }

    if (lstat(argv[1], &sb) == -1) {
        perror("파일 정보를 가져올 수 없습니다.");
        exit(1);
    } else {
        getcwd(buffer, FILENAME_MAX);
        printf("%s: 심볼릭 링크%s.\n", buffer, S_ISLNK(sb.st_mode) ? "입니다" : "가 아닙니다");
    }

    return 0;
}
