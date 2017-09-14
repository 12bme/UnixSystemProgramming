#include <sys/types.h>
#include <sys/socket.h>

// s: socket 함수가 생성한 소켓 기술자
// buf: 전송받은 메시지를 저장할 메모리 주소
// len: buf의 크기
// flags: 데이터를 주고받는 방법을 지정한 플래그
ssize_t recv(int s, void *buf, size_t len, int flags);
