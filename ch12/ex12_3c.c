#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORTNUM 9002

int main(void) {
    int sd, len;
    char buf[256];
    struct sockaddr_in sin;

    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 서버와 연결하기 위해 서버의 주소를 지정하고 소켓을 생성한다.
    if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // connect 함수를 호출해 서버와 연결을 요청한다.
    printf("==> Create Socket\n");
    if(connect(sd, (struct sockaddr *)&sin, sizeof(sin))) {
        perror("connect");
        exit(1);
    }

    // 서버에서 메시지를 받아 출력한다.
    printf("==> Connect Server\n");
    if((len = recv(sd, buf, sizeof(buf), 0)) == -1) {
        perror("recv");
        exit(1);
    }
    buf[len] = '\0';

    printf("==> From Server : %s\n", buf);

    // 소켓을 닫는다.
    close(sd);

    return 0;
}
