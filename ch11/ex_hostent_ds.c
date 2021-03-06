struct hostent {
    char *h_name;       // 호스트명을 저장
    char **h_aliases;   // 호스트를 가리키는 다른 이름들을 저장
    int  h_addrtype;    // 호스트 주소의 형식을 지정
    int  h_length;      // 주소의 길이를 저장
    char **h_addr_list; // 해당 호스트의 주소 목록 저장
};
