/* program ex03-01.c */
//#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    int filedes, fdnew1, fdnew2;    // 파일 기술자(File Descriptor)
    ssize_t nread;  // read()로 읽은 바이트 수
    off_t newpos;   // 읽기/쓰기 포인터 위치

    char buffer[1024];
    char content[] = "Hello, my friend!\n";

    filedes = open("data.txt", O_RDWR); // 파일을 읽기 쓰기용으로 개방

    nread = read(filedes, buffer, sizeof(buffer) - 1);    // 파일 읽기
    printf("%s", buffer);

    write(filedes, content, strlen(content));   // 파일 쓰기

    newpos = lseek(filedes, (off_t) 0, SEEK_SET);   // 읽기/쓰기 포인터 위치를 맨 처음(SEEK_SET)으로 이동
    nread = read(filedes, buffer, sizeof(buffer) - 1);
    printf("%s", buffer);

    close(filedes);  // 파일 닫기

    fdnew1 = open("newdata1.txt", O_RDWR | O_CREAT, 0644);   // 파일 접근권한 8진수 0644(rw-r--r--)
    fdnew2 = creat("newdata2.txt", 0644);

    close(fdnew1);
    close(fdnew2);
    unlink("newdata2.txt"); // 파일 삭제

    return 0;
}
