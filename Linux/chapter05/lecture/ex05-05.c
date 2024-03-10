#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    DIR *dirp;
    const struct dirent *dentry;

    if ((dirp = opendir(".")) == NULL)
        exit(1);

    puts("존재하는 파일 목록");
    while ((dentry = readdir(dirp)) != NULL) {
        if (dentry->d_ino != 0)
            puts(dentry->d_name);
    }

    rewinddir(dirp);    // 디렉터리 포인터가 가리키는 디렉터리 항을 첫 번째 항으로 초기화

    puts("\n삭제된 파일 목록");
    while ((dentry = readdir(dirp)) != NULL) {
        if (dentry->d_ino == 0)     // 삭제된 파일(아이노드 번호 0)만 출력
            puts(dentry->d_name);
    }

    closedir(dirp);

    return 0;
}
