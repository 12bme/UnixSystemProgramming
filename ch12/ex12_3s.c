#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORTNUM 9002

int main(void) {
    struct sockaddr_in sin, cli;
    int sd, ns, clientlen = sizeof(cli);

    // socket 함수로 소켓을 생성하고 
    if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    printf("** Create Socket\n");

    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 특정 IP 주소와 연결한 다음
    if(bind(sd, (struct sockaddr *)&sin, sizeof(sin))) {
        perror("bind");
        exit(1);
    }
    printf("** Bind Socket\n");

    // listen 함수로 클라이언트의 접속을 5개까지 처리한다고 설정한다.
    if(listen(sd, 5)) {
        perror("listen");
        exit(1);
    }
    printf("** Listen Socket\n");

    while(1) {
        // accept 함수를 사용해 클라이언트의 접속 요청을 받는다.
        if((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1) {
            perror("accept");
            exit(1);
        }
        printf("** Accept Client\n");

        // fork 함수로 자식 프로세스를 생성해 클라이언트의 응답을 처리하게 한다.
        switch(fork()) {
            // 클라이언트와 통신할 수 있는 소켓 기술자(ns)를
            // 표준 출력으로 복사한뒤, execl 함수로 han 프로세스를 실행한다.
            // han은 표준 출력을 간단한 메시지를 출력하는 프로세스다.
            case 0:
                printf("** Fork Client\n");
                close(sd);
                dup2(ns, STDIN_FILENO);
                dup2(ns, STDOUT_FILENO);
                close(ns);
                execl("./han", "han", (char *)0);
        }
        close(ns);
    }

    return 0;
}
