#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *originalname = "test.txt";
    char *hardfilename = "test.txt.hard";
    char *softfilename = "test.txt.soft";

    int filedes;
    mode_t oldmask;
    char buffer[1024];
    int nread;
    struct stat finfo;

    oldmask = umask(0377);  // 파일을 생성할 때 적용하는 접근 권한 중 특정값의 사용을 제한

    if ((filedes = open(originalname, O_CREAT, 0755)) == -1) {    // 초기 접근 권한 0755로 생성하지만 umask에 의해 실제로는 0400으로 설정
        perror("파일 열기 실패");
        exit(1);
    } else {
        close(filedes);     // 파일 닫기
    }

    if (access(originalname, W_OK) == -1) {     // 파일 쓰기 작업 불가일 경우
        fprintf(stderr, "%s is not writable\n", originalname);
        chmod(originalname, 0644);  // 쓰기 작업 가능한 새로운 접근 권한 설정
    }

    if (link(originalname, hardfilename) == -1) {   // 하드 링크 생성
        perror("하드 링크 생성 실패");
        exit(1);
    } else {
        symlink(originalname, softfilename);    // 소프트 링크 생성
    }

    if (rename(hardfilename, "newname.txt") == -1) {    // 하드 링크 파일명을 변경
        perror("하드 링크 파일명 변경 실패");
        exit(1);
    }

    if ((nread = readlink(softfilename, buffer, sizeof(buffer))) < 0) { // 가리키는 대상이 아닌 소프트 링크 파일의 실제 내용 읽기
        perror("소프트 링크 읽기 실패");
        exit(1);
    }

    if (write(1, buffer, nread) != nread) {    // stdout(fd=1)에 쓰기: 표준 출력
        perror("표준 출력 중 오류 발생");
        exit(1);
    }

    if (stat(originalname, &finfo) == -1) { // 아이노드 블록에서 test.txt 파일 정보를 가져온 후 구조체 변수 finfo에 저장
        perror("파일 정보 가져오기 실패");
        exit(1);
    }

    printf("\n%s\n", originalname);
    printf("File mode: %o\n", finfo.st_mode);
    printf("File size: %ld\n", finfo.st_size);
    printf("Num of blocks: %ld\n", finfo.st_blocks);

    return 0;
}
