struct shmid_ds {
    struct ipc_perm     shm_perm;     // IPC 공통 구조체(ipc_perm)를 의미
    size_t              shm_segsz;    // 공유 메모리 세그먼트의 크기를 바이트 단위로 나타낸다.
    struct anon_map     *shm_amp;     // 
    pid_tt_t            shm_lpid;     // 마지막으로 shmop 동작을 한 프로세스의 ID
    pid_t               shm_cpid;     // 공유 메모리를 생성한 프로세스의 ID
    shmatt_t            shm_nattch;   // 공유 메모리를 연결하고 있는 프로세스의 개수
    ulong_t             shm_cnattch;  // 
    time_t              shm_atime;    // 마지막으로 공유 메모리를 연결(shmat)한 시각
    int32_t             shm_pad1;     // 
    time_t              shm_dtime;    // 마지막으로 공유 메모리의 연결을 해제(shmdt)한 시각
    int32_t             shm_pad2;     // 
    time_t              shm_ctime;    // 마지막으로 공유 메모리의 접근 권한을 변경한 시각
    int32_t             shm_pad3;     // 
    int32_t             shm_pad4[4];  // 
};
