#include <netdb.h>
// addr: 검색하려는 IP 주소 & len: addr 길이 & type: IP 주소 형식
struct hostent *gethostbyaddr(const char *addr, int len, int type);
