#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char *path = "./tempdir/";

    if (access(path, F_OK) == 0) {
        puts("디렉토리가 이미 존재합니다.");
    } else {
        if (mkdir(path, 0660) == 0) {  // 디렉토리 생성
            puts("디렉토리 생성 완료");
        } else {
            perror("디렉토리 생성 실패");
            exit(1);
        }
    }

//    if (unlink(path) < 0) {   // unlink()는 디렉토리 삭제 불가
    if (remove(path) != 0) { // 비어 있는 디렉토리만 삭제 가능
        perror("디렉토리 삭제 실패");
        exit(1);
    } else {
        puts("디렉토리 삭제 성공");
    }

    if (access(path, F_OK) != 0) {
        puts("디렉토리가 존재하지 않습니다.");
    }

    return 0;
}
