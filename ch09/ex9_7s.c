#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    int pd, n;
    char msg[] = "Hello, FIFO";

    printf("Server =====\n");

    // mkfifo 함수로 HAN-FIFO라는 FIFO 파일을 생성한다.
    if(mkfifo("./HAN-FIFO", 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }

    // 서버에서 클라이언트로 데이터를 전송할 것이므로
    // HAN-FIFO 파일을 쓰기 전용으로 연다.
    if((pd = open("./HAN-FIFO", O_WRONLY)) == -1) {
        perror("open");
        exit(1);
    }

    printf("To Client : %s\n", msg);

    // 클라이언트로 "Hello, FIFO"라는 메시지를 전송한다.
    n = write(pd, msg, strlen(msg)+1);
    if (n == -1) {
        perror("write");
        exit(1);
    }
    close(pd);

    return 0;
}
