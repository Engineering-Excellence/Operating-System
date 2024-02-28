#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void) {
    int fdin, fdout;
    ssize_t nread;
    char buffer[1024];

    fdin = open("temp1.txt", O_RDONLY);
    fdout = open("temp2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);  // 새롭게 저장하려는 데이터가 기존 데이터보다 적을 경우 일부만 덮어쓰기 때문에 O_TRUNC 필요

    /* 정상적으로 읽어 들인 내용이 1 바이트 이상인 동안 반복문 수행 */
    while ((nread = read(fdin, buffer, sizeof(buffer) - 1)) > 0) {
        if (write(fdout, buffer, nread) < nread) {
            /* write가 비정상적으로 수행됨(실패) */
            fprintf(stderr, "write 실패\n");
            close(fdin);
            close(fdout);
        }
    }

    /* 프로그램이 정상적으로 수행됨 */
    close(fdin);
    close(fdout);

    return 0;
}
