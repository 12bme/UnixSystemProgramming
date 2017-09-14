#include <netdb.h>
// port : 검색할 포트 번호, proto: "tcp" 또는 "udp"
struct servent *getservbyport(int port, cosnt char *proto);
