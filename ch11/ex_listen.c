#include <sys/types.h>
#include <sys/socket.h>

// s: socket 함수가 생성한 소켓 기술자.
// backlog: 최대 허용 클라이언트 수
int liten(int s, int backlog);
