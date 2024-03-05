#include <sys/stat.h>   // mkdir 함수를 사용하기 위한 헤더 파일
#include <unistd.h>     // rmdir 함수를 사용하기 위한 헤더 파일

int main(void) {
    // 디렉토리 생성
    mkdir("test_dir1", 0755);
    mkdir("test_dir2", 0755);

    // 디렉토리 삭제
    rmdir("test_dir2");

    return 0;
}
