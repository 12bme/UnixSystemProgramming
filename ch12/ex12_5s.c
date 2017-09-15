#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORTNUM 9000

int main(void) {
    char buf[256];
    struct sockaddr_in sin, cli;
    int sd, clientlen = sizeof(cli);

    // 인터넷 소켓을 사용하는 소켓을 생성한다.
    // 소켓을 생성할 때 통신 방식은 SOCK_DGRAM으로 지정해
    // UDP를 사용하도록 한다.
    if((sd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // 소켓 주소 구조체에 서버의 주소를 지정한다.
    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family  = AF_INET;
    sin.sin_port    = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1"); 

    // 위에서 생성한 소켓을 bind 함수를 사용해
    // 다음 행에서 설정한 IP주소/포트 번호와 연결한다.
    if(bind(sd, (struct sockaddr *)&sin, sizeof(sin))) {
        perror("bind");
        exit(1);
    }

    while(1) {
        // recvfrom 함수를 호출해 클라이언트에서 오는 메시지를 받는다.
        // recvfrom 함수는 메시지를 보낸 클라이언트와 주소도 함께 알려주므로
        // 이 주소를 사용해 클라이언트로 메시지를 보낼 수 있다.
        if((recvfrom(sd, buf, 255, 0, (struct sockaddr *)&cli, &clientlen)) == -1) {
            perror("recvfrom");
            exit(1);
        }
        printf("** From Client : %s\n", buf);
        
        strcpy(buf, "Hello Client");
        // 클라이언트로 간단한 메시지로 보낸다.
        // sendto 함수에는 목적지의 주소를 인자로 지정해야 한다.
        if((sendto(sd, buf, strlen(buf) + 1, 0, (struct sockaddr *)&cli, sizeof(cli))) == -1) {
            perror("sendto");
            exit(1);
        }
    }

    return 0;
}
