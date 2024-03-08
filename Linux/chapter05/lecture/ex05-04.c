#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    DIR *dirp;
    const struct dirent *dentry;

    if ((dirp = opendir(".")) == NULL)  // 현재 디렉터리를 개방해서 디렉터리 포인터에 저장
        exit(1);

    while ((dentry = readdir(dirp)) != NULL) {  // 현재 포인터가 가리키는 항을 읽고 디렉터리 포인터는 다음 항을 가리킴
        if (dentry->d_ino != 0) // 삭제된 파일(아이노드 번호 0) 제외
            puts(dentry->d_name);
    }

    closedir(dirp); // 개방된 디렉터리 닫기

    return 0;
}
