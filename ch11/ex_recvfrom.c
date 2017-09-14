#include <sys/types.h>
#include <sys/socket.h>

// s: socket 함수가 생성한 소켓 기술자
// buf: 전송받은 메시지를 저장할 메모리 주소
// len: 메시지의 크기
// flags: 데이터를 주고받는 방법을 지정한 플래그
// from: 메시지를 보내는 호스트의 주소
// fromlen: from의 크기
ssize_t recvfrom(int s, void *buf, size_t len, int flags,
                struct sockaddr *from, int *fromlen);
