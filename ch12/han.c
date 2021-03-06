#include <unistd.h>
#include <stdio.h>

int main(void) {
    // han 프로세스에서 표준 출력으로 메시지를 출력하면
    // 기본 표준 출력인 모니터가 아닌 클라이언트 프로세스로 전달된다.
    // 이는 부모 프로세스인 서버 프로그램에서 exec 함수를 호출하기 전에
    // 소켓 기술자를 표준 출력으로 복제했기 때문이다.
    printf("Welcome to Server, from Han!");
    // sleep 함수는 프로세스 목록을 확인할 수 있게 시간을 지연시킨다.
    sleep(5);

    return 0;
}
