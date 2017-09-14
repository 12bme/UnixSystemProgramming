#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    in_addr_t addr;
    struct hostent *hp;
    struct in_addr in;

    // 문자열로 된 IP 주소를 이진 형태로 변환.
    if((addr = inet_addr("127.0.0.1")) == (in_addr_t)-1) {
        printf("Error: inet_addr(127.0.0.1)\n");
        exit(1);
    }

    // gethostbyaddr 함수에 정수형으로 변환된 IP 주소를 인자로 지정하고
    // 호스트 정보를 검색한다. gethostbyaddr 함수의 첫번째 인자는 char *이므로
    // 형변환을 수행해 지정한다. 주소는 4바이트 크기고, 인터넷 주소이므로 AF_INET을 지정한다.
    hp = gethostbyaddr((char *)&addr, 4, AF_INET);
    if(hp == NULL) {
        (void)printf("Host information not found\n");
        exit(2);
    }

    // 검색된 호스트명을 출력한다.
    printf("Name=%s\n", hp->h_name);

    // hostent 구조체의 항목으로 리턴된 IP 주소를 출력한다.
    // 이 IP 주소는 이진값으로 hostent 구조체의 항목에서 in_addr 구조체로 복사한 후
    // 문자열 형태로 변환해야 한다. in_add 구조체에 값을 지정하고,
    // inet_ntoa 함수로 in_addr 구조체를 인자로 받아 문자열로 변환하고 출력한다.
    (void)memcpy(&in.s_addr, *hp->h_addr_list, sizeof(in.s_addr));
    printf("IP=%s\n", inet_ntoa(in));

    return 0;
}
