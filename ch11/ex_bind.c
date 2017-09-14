#include <sys/types.h>
#include <sys/socket.h>

// s: socket 함수가 생성한 소켓 기술자
// name: 소켓의 이름을 표현하는 구조체
// namelen: name의 크기
int bind(int s, const struct sockaddr *name, int namelen);
