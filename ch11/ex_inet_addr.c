#include <sys/types.h>
#include <sys/scoket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// cp: 문자열 형태 IP 주소
in_addr_t inet_addr(const char *cp);
