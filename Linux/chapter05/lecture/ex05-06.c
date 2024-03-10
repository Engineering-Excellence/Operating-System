#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 256

void printcwd() {
    char buffer[BUF_SIZE];

    if (getcwd(buffer, BUF_SIZE) == NULL)   // 현재 작업 디렉터리의 절대 경로를 버퍼에 저장
        exit(1);
    puts(buffer);
}

int main(void) {
    printcwd();
    chdir("/usr/include");
    printcwd();
    chdir("..");
    printcwd();

    return 0;
}
