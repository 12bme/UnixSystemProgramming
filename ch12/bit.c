#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char buf[256];
    int len, ns;

    // 명령행 인자(문자열)로 전달받은 소켓 기술자를 정수형으로 변환한다.
    ns = atoi(argv[1]);

    // 간단한 환영 메시지를 클라이언트로 전송한다.
    strcpy(buf, "Welcome to Server, from Bit");
    if((send(ns, buf, strlen(buf) + 1, 0)) == -1) {
        perror("send");
        exit(1);
    }

    // 클라이언트에서 보낸 메시지를 받아 출력한다.
    if((len=recv(ns, buf, strlen(buf), 0)) == -1) {
        perror("recv");
        exit(1);
    }
    printf("@@ [Bit] From Client: %s\n", buf);
    close(ns);

    return 0;
}
