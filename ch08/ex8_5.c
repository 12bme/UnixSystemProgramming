#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int fd;
    pid_t pid;
    caddr_t addr; // a legacy BSD type(low level calls like mmap)
    struct stat statbuf;

    if(argc != 2) {
        fprintf(stderr, "Usage : %s filename\n", argv[0]);
        exit(1);
    }

    if(stat(argv[1], &statbuf) == -1) { //stat 함수로 파일의 속성 정보를 검색해 파일의 크기를 알아낸다.
        perror("stat");
        exit(1);
    }

    if((fd = open(argv[1], O_RDWR)) == -1) { // 메모리에 매핑할 데이터 파일을 연다.
        perror("open");
        exit(1);
    }
    // 파일을 메모리에 매핑한다.
    addr = mmap(NULL, statbuf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, (off_t)0);

    if(addr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    close(fd);

    switch (pid = fork()) { // fork 함수를 실행해 자식 프로세스를 생성한다. 자식 프로세스는 부모 프로세스를 상속하므로 매핑된 메모리의 시작 주소인 addr을 공유한다.
        case -1: /* fork failed */
            perror("fork");
            exit(1);
            break;
        case 0: /* child process */
            printf("1. Child Process : addr=%s", addr);
            sleep(1);
            addr[0] = 'x';  // 자식 프로세스가 addr[0]의 내용을 'x'로 변경한다. 54행에 해당하는 출력 내용을 보면 자식 프로세스가 변경한 값을 부모 프로세스로 읽을 수 있음을 확인할 수 있다.
            printf("2. Child Process : addr=%s", addr);
            sleep(2);
            printf("3. Child Process : addr=%s", addr);
            break;
        default: /* parent process */
            printf("1. Parent process : addr=%s", addr);
            sleep(2);
            printf("2. Parent process : addr=%s", addr);
            addr[1] = 'y';  // 46행과 반대로 부모 프로세스가 addr[1]의 내용을 'y'로 변경한다.
            printf("3. Parent process : addr=%s", addr);
            break;
    }
}
