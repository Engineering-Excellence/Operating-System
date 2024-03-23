#include <unistd.h>
#include <stdio.h>

int main(void) {
    char *arg[] = {"ls", "-l", NULL};   // (char *) 0 == NULL: 마지막 인자는 반드시 NULL 포인터 사용

    puts("Before executing ls -l");
    execv("/bin/ls", arg);  // execv는 인자로 넘겨주는 문자열들을 문자열 포인터의 배열로 넘겨줌
    puts("After executing ls -l");

    return 0;
}
