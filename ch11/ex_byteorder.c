#include <sys/types.h>
#include <netinet/in.h>
#include <inttypes.h>

// hostlong, hostshort: 호스트 바이트 순서로 저장된 값
// netlong, netshort: 네트워크 바이트 순서로 저장된 값
uint32_t htonl(unit32_t hostlong); 
uint16_t htons(unit16_t hostshort);
uint32_t ntohl(unit32_t netlong);
uint16_t ntohs(unit16_t netshort);
