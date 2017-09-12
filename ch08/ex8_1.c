#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int fd;
    caddr_t addr;
    struct stat statbuf;

    if(argc != 2) {     // 명령행 인자로 파일명을 제대로 지정했는지 확인한다.
        fprintf(stderr, "Usage : %s filename\n", argv[0]);
        exit(1);
    }

    if(stat(argv[1], &statbuf) == -1) {  // stat 함수를 사용해 파일의 크기를 알아낸다.
        perror("stat");
        exit(1);
    }

    if((fd = open(argv[1], O_RDWR)) == -1) {  //파일을 열고
        perror("open");
        exit(1);
    }

    addr = mmap(NULL, statbuf.st_size, PROT_READ|PROT_WRITE,  // 파일을 열고 mmap 함수로 메모리 매핑을 한다.
                MAP_SHARED, fd, (off_t)0);      // 매핑된 메모리 영역의 읽기와 쓰기가 가능하게 PROT_READ|PROT_WRITE 로 지정하고 MAP_SHARED 플래그를 지정한다.
    if(addr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }   // 파일의 내용을 메모리에 매핑했으므로 파일을 닫느다. 열린 파일을 닫아도 매핑된 메모리 주소인 addr을 이용해 데이터를 읽거나 쓸 수 있다.
    close(fd);

    printf("%s", addr);   // addr이 가리키는 주소에 저장된 내용을 모두 출력한다.

    return 0;
}

// 먼저 명령행 인자로 지정한 파일인 mmap.dat의 내용을 살펴본 후 실행 결과를 살펴보면 파일의 내용이 모두 출력되었음을 확인할 수 있다.
