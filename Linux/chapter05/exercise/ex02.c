#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    DIR *dirp;
    struct dirent *dentry;
    int filecnt = 0, dircnt = 0;

    if (argc != 2) {
        perror("파라미터 개수가 잘못 입력되었습니다.");
        exit(1);
    }

    if ((dirp = opendir(argv[1])) == NULL) {
        perror("디렉터리를 열 수 없습니다.");
        exit(1);
    } else {
        while ((dentry = readdir(dirp)) != NULL) {
            if (strcmp(dentry->d_name, ".") == 0) {
                puts(".: 현재 디렉터리");
            } else if (strcmp(dentry->d_name, "..") == 0) {
                puts("..: 부모 디렉터리");
            } else if (dentry->d_type == DT_DIR) {
                dircnt++;
                printf("%s: 하위 디렉터리\n", dentry->d_name);
            } else {
                filecnt++;
                printf("%s: 파일\n", dentry->d_name);
            }
        }

        closedir(dirp);

        printf("\n파일의 개수: %d개\n", filecnt);
        printf("하위 디렉터리의 개수: %d개\n", dircnt);
    }

    return 0;
}
