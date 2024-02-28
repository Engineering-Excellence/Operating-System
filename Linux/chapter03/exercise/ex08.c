#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    int filedes;
    char buffer[1024] = {'\0'};

    if ((filedes = open("./ex08.txt", O_RDWR)) < 0) {   // 파일 열기
        perror("파일 열기 실패");
        exit(1);
    }

    while ((read(filedes, buffer, sizeof(buffer) - 1)) > 0) {   // 파일 읽기
        for (int i = 0; i < strlen(buffer) - 1; ++i) {
            buffer[i] = toupper(buffer[i]);     // 알파벳 소문자를 대문자로 변환
        }
    }

    if (lseek(filedes, (off_t) 0, SEEK_SET) == (off_t) - 1) {   // 읽기/쓰기 포인터를 처음으로 이동
        perror("읽기/쓰기 포인터 이동중 오류 발생");
        exit(1);
    }

    if ((write(filedes, buffer, strlen(buffer))) != strlen(buffer)) {   // 파일 덮어쓰기
        perror("파일 덮어쓰기 중 오류 발생");
        exit(1);
    }

    close(filedes);     // 파일 닫기

    return 0;
}
