#include <unistd.h>
#include <stdio.h>

int main(void) {
    puts("Before executing ls -l");
    execl("/bin/ls", "ls", "-l", (char *) 0);   // execl은 인자로 넘겨주는 문자열들을 하나씩 여러개로 나열
    puts("After executing ls -l");  // exec 계열 함수가 정상 실행시 호출 프로세스가 종료되기 때문에 이후 코드는 실행되지 않음

    return 0;
}
