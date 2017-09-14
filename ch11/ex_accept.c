#include <sys/types.h>
#include <sys/socket.h>

// s: socket 함수가 생성한 소켓 기술자
// addr: 접속을 수락한 클라이언트의 IP 정보
// addrlen: addr 크기
int accept(int s, struct sockaddr *addr, socklen_t *addrlen);
