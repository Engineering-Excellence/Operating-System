#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (link(argv[1], argv[2]))
        perror("hard-link failed");

    return 0;
}
