#include <stdio.h>
#include <stdlib.h>

void func1(void);

void func2(void);

int main(void) {
    puts("Hello!");

    /*
        int atexit(void (*function)(void));
        Clean-Up-Action을 위해 function 주어진 함수들을 최대 32개 등록하여 프로세스가 종료될 때 역순(스택)으로 호출된다.
        개방한 파일에 대한 쓰기 작업을 마저하거나 자식 프로세스를 강제 종료시키는 등으로 활용.
     */
    atexit(func1);
    atexit(func2);

    puts("Bye!");
    exit(0);
}

void func1(void) {
    puts("func1");
}

void func2(void) {
    puts("func2");
}
