#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int filedes;
    char *pathname = "temp.txt";

    if ((filedes = open(pathname, O_CREAT | O_RDWR, 0644)) == -1) {
        fprintf(stderr, "File open error!");
        exit(1);
    }

    close(filedes);

    return 0;
}
