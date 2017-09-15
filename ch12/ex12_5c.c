#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORTNUM 9000

int main(void) {
    int sd, n;
    char buf[256];
    struct sockaddr_in sin;

    // 소켓을 생성한다. TCP 기반 프로그램과 달리 connect 함수를 호출하지 않는다.
    if((sd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // 서버의 주소를 소켓 주소 구조체에 설정한다.
    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

    // sendto  함수를 호출해 메시지를 서버로 전송한다.
    strcpy(buf, "I am a client");
    if(sendto(sd, buf, strlen(buf)+1, 0, (struct sockaddr *)&sin, sizeof(sin)) == -1) {
        perror("sendto");
        exit(1);
    }

    //서버에서 전송한 응답 메시지를 recvfrom 함수로 읽어 출력한다.
    n = recvfrom(sd, buf, 255, 0, NULL, NULL);
    buf[n] = '\0';
    printf("** From Server : %s\n", buf);

    return 0;
}
