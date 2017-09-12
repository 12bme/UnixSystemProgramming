#define _CRT_SECURE_NO_WARNINGS
#include <sys/mman.h>
#include <sys/stat.h> //파일정보를 담고있는 헤더파일
#include <fcntl.h> //파일을 열고, 잠금 및 다른 작업을 할 수 있음.
#include <unistd.h> // 다양한 필수 POSIX 함수와 상수.
#include <stdlib.h> //C언어의 표준 라이브러리로, 문자열 변환, 의사 난수 생성, 동적 메모리 관리 등의 함수들을 포함하고 있다.
#include <stdio.h> //Standar Input/Output library의 약어로써, C언어의 표준 라이브러리 함수의 매크로 정의, 상수, 여러 형의 입출력 함수가 포함된 헤더 파일
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *src_fp, *dest_fp;
    struct stat src_statbuf, dest_statbuf;
    char ch, *pwd;

    pwd = strcat(getenv("PWD"), "/");
    printf("PWD = %s\n", pwd);

    if(argc != 2) {
        fprintf(stderr, "Usage : %s source_filename\n", argv[0]);
        exit(1);
    }

    if(stat(argv[1], &src_statbuf) == -1) {
        perror("src_stat");
        exit(1);
    }

    if((src_fp = fopen(strcat(pwd, argv[1]), "r+")) == NULL) {
        perror("src_open");
        exit(1);
    }

    if((dest_fp = fopen(strcat(pwd, ".blog"), "w")) == NULL) {
        perror("dest_open");
        exit(1);
    }

    fputs("<pre class=\"brush:c\">", dest_fp);

    while((ch = fgetc(src_fp)) != EOF) {
        if('<'==ch) fputs("&lt;", dest_fp);
        else if('>'==ch) fputs("&gt;", dest_fp);
        else fputc(ch, dest_fp);
    }

    fputs("</pre>\n", dest_fp);

    fclose(src_fp);
    fclose(dest_fp);

    if(execlp("cat", "cat", pwd, (char *)NULL) == -1) {
        perror("execlp");
        exit(1);
    }

    return 0;
}
