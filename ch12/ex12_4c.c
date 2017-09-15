#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORTNUM 9000

int main(void) {
    int sd, len;
    char buf[256];
    struct sockaddr_in sin;

    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family  = AF_INET;
    sin.sin_port    = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 소켓을 생성하고
    if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // 생성한 소캣을 통해 서버와 연결한다.
    printf("==> Create Socket\n");
    if(connect(sd, (struct sockaddr *)&sin, sizeof(sin))) {
        perror("connect");
        exit(1);
    }

    printf("==> Connect Server\n");
    // 서버에서 메시지를 전달 받는다.
    if((len = recv(sd, buf, sizeof(buf), 0)) == -1) {
        perror("recv");
        exit(1);
    }
    buf[len] = '\0';

    // 서버의 메시지를 출력하고
    printf("==> From Server : %s\n", buf);

    // 답장 메시지를 작성해 send 함수를 통해 서버로 전송한다.
    strcpy(buf, "I want a TELNET Service.");
    if(send(sd, buf, sizeof(buf) + 1, 0) == -1) {
        perror("send");
        exit(1);
    }

    close(sd);

    return 0;
}
