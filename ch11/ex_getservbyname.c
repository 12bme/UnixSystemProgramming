#include <netdb.h>

// name : 검색할 포트명, proto: "tcp" 또는 "udp"
struct servent *getservbyname(const char *name, const char *proto);
