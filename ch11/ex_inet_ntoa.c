#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// in_addr 구조체 형태 IP 주소
char *inet_ntoa(const struct in_addr in);
