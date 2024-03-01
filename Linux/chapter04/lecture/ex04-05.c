#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char *path1 = "test1.txt", *path2 = "test2.txt";
    mode_t mode1, mode2;
    mode1 = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    mode2 = 0644;   // mode1 == mode2

    if (chmod(path1, mode1) == -1) {
        fprintf(stderr, "%s에 대한 권한을 변경할 수 없습니다.\n", path1);
        exit(1);
    }
    if (chmod(path2, mode2) == -1) {
        fprintf(stderr, "%s에 대한 권한을 변경할 수 없습니다.\n", path2);
        exit(1);
    }

    puts("권한 변경 완료");

    return 0;
}
