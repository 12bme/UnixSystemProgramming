#include <sys/types.h>
#include <sys/socket.h>

// s: socket 함수가 생성한 소켓 기술자
// msg: 전송할 메시지를 지정한 메모리 주소
// len: 메시지의 크기
// flags: 데이터를 주고받는 방법을 지정한 플래그
ssize_t send(int s, const void *msg, size_t len, int flags);
