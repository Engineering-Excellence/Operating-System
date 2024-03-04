#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>

int main(void) {
    char buffer[256];
    DIR *dirp;  // opendir로 개방한 디렉터리에 대한 포인터
    const struct dirent *dentry;  // readdir로 읽어들인 디렉터리 항에 대한 정보

    getcwd(buffer, sizeof(buffer)); // 현재 작업 디렉터리를 버퍼에 저장
    puts(buffer);

    mkdir("apple", 0755);
    mkdir("banana", 0755);

    chdir("apple");

    getcwd(buffer, sizeof(buffer));
    puts(buffer);

    close(open("test.txt", O_CREAT | O_RDWR, 0644));    // 파일 생성 직후 닫기(크기 0)

    chdir("..");

    rmdir("apple");     // test.txt가 존재하므로 디렉터리 삭제 실패
    rmdir("banana");    // 빈 디렉터리 삭제 성공

    dirp = opendir("apple");

    while ((dentry = readdir(dirp)) != NULL)
        if (dentry->d_ino != 0)
            puts(dentry->d_name);   // 디렉터리가 저장중인 파일명을 출력

    rewinddir(dirp);    // 개방된 apple 디렉터리의 포인터를 제일 처음의 항으로 이동

    while ((dentry = readdir(dirp)) != NULL)
        if (dentry->d_ino != 0)
            puts(dentry->d_name);

    closedir(dirp);     // 개방된 apple 디렉터리 닫기

    return 0;
}
