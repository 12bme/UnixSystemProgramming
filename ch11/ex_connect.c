#include <sys/types.h>
#include <sys/socket.h>

// s: socket 함수가 생성한 소켓 기술자
// name: 접속하려는 서버의 IP 정보
// namelen: name의 크기
int connect(int s, const struct sockaddr *name, int namelen);
