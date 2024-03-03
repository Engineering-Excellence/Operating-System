#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int filedes;
    char *filename = "a.txt";
    char *symlinkname = "b.txt";

    if ((filedes = creat(filename, O_TRUNC)) == -1) {
        perror("파일 생성 실패");
        exit(1);
    } else {
        close(filedes);
    }

    if (symlink(filename, symlinkname) == -1) {
        perror("소프트 링크 생성 실패");
        exit(1);
    } else if (unlink(filename) == -1) {
        perror("파일 삭제 실패");
        exit(1);
    } else if (access(symlinkname, F_OK) == -1) {
        perror("파일이 존재하지 않습니다.");
        exit(1);
    } else {
        printf("%s 파일이 존재합니다.", symlinkname);
    }

    return 0;
}
