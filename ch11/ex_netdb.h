struct servent {
    char *s_name;       // 포트명을 지정
    char **s_aliases;   // 해당 서비스를 가리키는 다른 이름들 저장
    int  s_port;        // 포트 번호를 저장
    char *s_proto;      // 서비스에 사용하는 프로토콜의 종류
};
