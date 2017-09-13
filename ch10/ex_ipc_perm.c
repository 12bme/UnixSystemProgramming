struct ipc_perm {
    uid_t   uid;    // 구조체의 소유자 ID를 의미한다.
    gid_t   gid;    // 구조체의 소유 그룹 ID를 의미한다.
    uid_t   cuid;   // 구조체를 생성한 사용자 ID를 의미한다.
    gid_t   cgid;   // 구조체를 생성한 그룹 ID를 의미한다.
    mode_t  mode;   // 구조체에 대한 접근 권한을 의미한다.
    uint_t  seq;    // 슬롯의 일련번호를 의미한다. 
    key_t   key;    // 키값을 의미한다.
    int     pad[4]; // 향후 사용을 위해 예약되어 있는 영역이다.
}
