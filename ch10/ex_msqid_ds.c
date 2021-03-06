struct msqid_ds {
    struct ipc_perm     msg_perm;     // IPC 공통 구조체(ipc_perm)을 의미한다.
    struct msg          *msg_first;   // 메시지 큐에 있는 첫번째 메시지에 대한 포인터다.
    struct msg          *msg_last;    // 메시지 큐에 있는 마지막 메시지에 대한 포인터다.
    msglen_t            msg_cbytes;   // 현재 메시지 큐에 있는 메시지의 총 바이트 수다.
    msgqnum_t           msg_qnum;     // 메시지 큐에 있는 메시지의 개수다
    msglen_t            msg_qbytes;   // 메시지 큐의 최대 크기(바이트 수)다.
    pid_t               msg_lspid;    // 마지막으로 메시지를 보낸 프로세스의 ID다.
    pid_t               msg_lrpid;    // 마지막으로 메시지를 읽은 프로세스의 ID다.
    time_t              msg_stime;    // 마지막 으로 메시지를 보낸 시각이다.
    int32_t             msg_pad1;     // 시간 정보를 확장하기 위한 예비 공간이다.
    time_t              msg_rtime;    // 마지막으로 메시지를 읽은 시각이다.
    int32_t             msg_pad2;     // 시간 정보를 확장하기 위한 예비 공간이다.
    time_t              msg_ctime;    // 마지막으로 메시ㅣ 큐의 권한을 변경한 시각이다.
    int32_t             msg_pad3;     // 시간 정보를 확장하기 위한 예비 공간이다.
    short               msg_cv;
    short               msg_qnum_cv;
    long                msg_pad4[3];
}
