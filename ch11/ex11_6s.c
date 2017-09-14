#include <sys/un.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SOCKET_NAME     "hbsocket"

int main(void) {
    char buf[256];
    struct sockaddr_un ser, cli;
    int sd, nsd, len, clen;

    unlink(SOCKET_NAME);
    // 소켓을 생성하고 소켓 주소 구조체에 값을 지정한다.
    if((sd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset((char *)&ser, 0, sizeof(struct sockaddr_un));
    // 소켓 패밀리를 AF_UNIX로 지정하고 소켓 경로명을 지정한다.
    ser.sun_family = AF_UNIX;
    strcpy(ser.sun_path, SOCKET_NAME);
    len = sizeof(ser.sun_family) + strlen(ser.sun_path);

    // bind 함수로 소켓 기술자를 소켓 주소 구조체와 연결해 이름을 등록한다.
    if(bind(sd, (struct sockaddr *)&ser, len)) {
        perror("bind");
        exit(1);
    }

    // listen 함수를 호출해 통신할 준비를 마쳤음을 알린다.
    if(listen(sd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Waiting...\n");
    // accept 함수를 호출해 클라이언트의 접속 요청을 수락하고,
    // 새로운 소켓 기술자를 생성해 nsd에 저장한다.
    if((nsd = accept(sd, (struct sockaddr *)&cli, &clen)) == -1) {
        perror("accept");
        exit(1);
    }

    // 클라이언트가 보낸 메시지를 recv 함수로 받아서 출력한다.
    if(recv(nsd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        exit(1);
    }

    printf("Received Message: %s\n", buf);

    // 출력을 완료 했으므로 소켓을 닫는다.
    close(nsd);
    close(sd);

    return 0;
}
