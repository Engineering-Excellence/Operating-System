#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void func1(void);

void func2(void);

int main(void) {
    puts("Hello!");

    // atexit()으로 종료시 실행할 함수 등록
    atexit(func1);
    atexit(func2);

    puts("Bye!");

    _exit(0);   // atexit()으로 함수가 등록되었지만 실행되지 않음
}

void func1(void) {
    puts("func1");
}

void func2(void) {
    puts("func2");
}
