#define FD_SETSIZE      54
FD_set  fdvar
FD_ZERO(&fdvar);        // fd_set을 초기화
FD_SET(1, &fdvar);      // fd 1비트 검색
FD_SET(4, &fdvar);      // fd 4비트 검색
FD_SET(5, &fdvar);      // fd 5비트 검색
