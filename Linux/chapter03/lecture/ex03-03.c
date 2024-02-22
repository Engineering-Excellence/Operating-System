#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int filedes1, filedes2;

    // 초기권한 0644로 파일 생성하여 쓰기 전용으로 개방 및 기존 내용 모두 삭제 후 읽기/쓰기 포인터를 파일 첫 번째 위치로 이동
    filedes1 = open("data1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);   // 기존 파일 존재시 변경방지: O_EXCL 플래그 추가하여 open
    filedes2 = creat("data2.txt", 0644);

    close(filedes1);    // 파일 닫기
    close(filedes2);

    return 0;
}
