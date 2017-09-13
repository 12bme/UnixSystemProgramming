#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int pd, n;
    char inmsg[80];

    // HAN-FIFO 파일을 읽기 전용으로 연다. 클라이언트 프로그램은 이미 HAN-FIFO 파일이 있다고
    // 가정하고 파일을 열고 있으므로 서버 프로그램을 먼저 실행해야 한다.
    if ((pd = open("./HAN-FIFO", O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    }

    printf("Client =====\n");
    write(1, "From Server : ", 13);

    // 반복문을 수행하며 FIFO 파일에서 데이터를 읽어와 출력한다.
    while((n=read(pd, inmsg, 80)) > 0)
        write(1, inmsg, n);

    if(n == -1) {
        perror("read");
        exit(1);
    }

    write(1, "\n", 1);
    close(pd);

    return 0;
}
