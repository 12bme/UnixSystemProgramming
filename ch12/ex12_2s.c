#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORTNUM 9000

int main(void) {
    char buf[256];
    struct sockaddr_in sin, cli;
    int sd, ns, clientlen = sizeof(cli);

    // socket 함수로 소켓을 생성하고
    if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family  = AF_INET;
    sin.sin_port    = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 특정 IP 주소와 연결한 후
    if(bind(sd, (struct sockaddr *)&sin, sizeof(sin))) {
        perror("bind");
        exit(1);
    }

    // listen 함수로 클라이언트의 접속을 5개까지 처리하도록 설정
    if(listen(sd, 5)) {
        perror("listen");
        exit(1);
    }

    while(1) {
        // accept 함수를 사용해 클라이언트의 접속 요청을 받는다.
        if((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1) {
            perror("accept");
            exit(1);
        }
        // fork 함수를 수행해 자식 프로세스를 생성하고
        // 자식 프로세스가 클라이언트의 응답을 처리하게 한다.
        switch (fork()) {
            case 0:
                close(sd);
                strcpy(buf, "Welcome to Server");
                if(send(ns, buf, strlen(buf) + 1, 0) == -1) {
                    perror("send");
                    exit(1);
                }

                if(recv(ns, buf, strlen(buf), 0) == -1) {
                    perror("recv");
                    exit(1);
                }
                printf("** From Client: %s\n", buf);
                sleep(5);
                exit(0);
        }
        close(ns);
    }

    return 0;
}
