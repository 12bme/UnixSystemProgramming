#include <netdb.h>
#include <stdio.h>

int main(void) {
    struct hostent *hent;
    // 호스트 파일의 처음으로 읽기 위치를 지정
    sethostent(0);
    // 호스트 파일에서 차례로 읽어 호스트명(h_name)을 출력
    while((hent = gethostent()) != NULL)
        printf("Name=%s\n", hent->h_name);
    // 호스트 파일을 닫는다.
    endhostent();

    return 0;
}
