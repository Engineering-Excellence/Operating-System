#include <dirent.h> // opendir, closedir, DIR 정의
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    DIR *dirp;

    if ((dirp = opendir("test_dir1")) == NULL) {
        perror("Error on opening directory test_dir1");
        exit(1);
    }

    /* 디렉터리 목록을 읽어오는 부분 */

    closedir(dirp);

    return 0;
}
