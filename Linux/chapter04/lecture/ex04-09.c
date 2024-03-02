#include <unistd.h>

int main(void) {
    char buffer[1024];
    int nread;

    nread = readlink("link.txt.soft-link", buffer, sizeof(buffer));
    write(1, buffer, nread);

    return 0;
}
