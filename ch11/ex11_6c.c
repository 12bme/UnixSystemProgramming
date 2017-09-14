#include <sys/un.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SOCKET_NAME     "hbsocket"

int main(void) {
    int sd, len;
    char buf[256];
    struct sockaddr_un ser;

    // 소켓을 생성한다.
    if((sd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // 소켓 주소 구조체에 값을 지정한다.
    memset((char *)&ser, '\0', sizeof(ser));
    ser.sun_family = AF_UNIX;
    strcpy(ser.sun_path, SOCKET_NAME);
    len = sizeof(ser.sun_family) + strlen(ser.sun_path);

    // 소켓 주소 구조체에 지정한 서버로 connect 함수를 사용해 연결을 요청한다.
    if(connect(sd, (struct sockaddr *)&ser, len) < 0) {
        perror("bind");
        exit(1);
    }

    // 서버로 메시지를 전송한다.
    strcpy(buf, "Unix Domain Socket Test Message");
    if(send(sd, buf, sizeof(buf), 0) == -1) {
        perror("send");
        exit(1);
    }
    close(sd);

    return 0;
}
