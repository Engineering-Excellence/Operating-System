#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

int main(void) {
    FILE *fp = NULL;
    size_t nread;
    char buffer[BUFF_SIZE];
    const char *path = "./temp0.txt";

    if ((fp = fopen(path, "r+")) != NULL) { // 파일 열기
        if ((nread = fread(buffer, sizeof(char), sizeof(buffer) - 1, fp)) >= 0) {   // 파일 읽기
            printf("읽은 바이트 수: %zu\n", nread);
            puts(buffer);
            printf("feof: %d\n", feof(fp)); // 파일의 끝에 도달하면 1을 반환
            printf("ftell: %ld\n", ftell(fp));  // 현재 파일 위치를 반환
            fclose(fp); // 파일 닫기
        } else {
            perror("파일 읽기 실패");
            exit(1);
        }
    } else {
        perror("파일 열기 실패");
        exit(1);
    }

    return 0;
}
