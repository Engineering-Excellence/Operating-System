#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int filedes;
    char *pathname = "temp.txt";

    // 파일 존재시 읽기 쓰기용 개방, 존재하지 않으면 초기권한 0644로 파일 생성 후 쓰기 전용 개방
    if ((filedes = open(pathname, O_CREAT | O_RDWR, 0644)) == -1) {
        fprintf(stderr, "File open error!");    // 파일 개방 실패시 에러 메시지 출력 후 프로그램 종료
        exit(1);
    }

    close(filedes); // 파일 닫기

    return 0;
}
