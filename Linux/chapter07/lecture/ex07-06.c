#include <unistd.h>

int main(void) {
    execl("ex07-05", "apple", "option", (char *) 0);    // execl 함수의 두 번째 인잣값을 프로그램 이름으로 지정하는 것이 관행이나, 필수는 아님

    return 0;
}
