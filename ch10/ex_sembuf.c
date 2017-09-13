struct sembuf {
    ushort_t    sem_num;    // 세마포어 번호를 의미
    short       sem_op;     // 세마포어 연산을 의미
    // 연산을 위한 플래그로, IPC_NOWAIT 또는 SEM_UNDO를 지정한다.
    // SEM_UNDO: 프로세스가 비정상적으로 갑자기 종료할 때
    //          세마포어 동작을 취소한다.
    short       sem_flg;
};
