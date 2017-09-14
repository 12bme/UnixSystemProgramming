#include <netdb.h>
#include <stdio.h>
 
int main(void) {
    struct servent *port;
         
    // 포트명을 검색하려면 getservbyname 함수에 서비스명을 인자로 지정한다.
    port = getservbyname("telnet", "tcp");
    // ntohs 함수를 사용해 검색 결과를 출력한다.
    printf("Name=%s, Prot=%d\n", port->s_name, ntohs(port->s_port));
                     
    // 포트 번호로 검색하려면 포트 번호를 NBO로 지정해야 한다.
    // getservbyport 함수의 첫번째 인자는 htons 함수를 사용해 포트 번호를
    // HBO에서 NBO로 변환해 지정한다.
    port = getservbyport(htons(21), "tcp");
    // ntohs 함수를 사용해 검색 결과를 출력한다.
    printf("Name=%s, Port=%d\n", port->s_name, ntohs(port->s_port));
                                             
    return 0;
}
