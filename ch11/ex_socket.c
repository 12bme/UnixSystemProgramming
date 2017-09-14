#include <sys/types.h>
#include <sys/socket.h>

// domain: 소켓 종류(유닉스 도메인 또는 인터넷 소켓)
// type: 통신 방식(TCP 또는 UDP)
// protocol: 소켓에 이용할 프로토콜
int socket(int domain, int type, int protocol);
