#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int filedes;
    mode_t oldmask;

    oldmask = umask(023);   // 그룹 사용자에게 쓰기 권한 제한, 기타 사용자에게 쓰기/실행 권한 제한
    filedes = open("ex04-02.txt", O_CREAT, 0777);   // 모든 권한을 주어서 생성하지만 프로세스 종료전까지 umask 제한 적용
    close(filedes);

    return 0;
}
