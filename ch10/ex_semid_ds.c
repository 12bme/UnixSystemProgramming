struct semid_ds {
    struct ipc_perm     sem_perm;       // IPC 공통 구조체를 의미한다.
    // 세마포어 집합에서 첫번째 세마포어의 주소다.
    // sem 구조체는 세마포어 집합에 있는 각 세마포어에 관한 정보를 저장한다.
    // sem 구조체는 <sys/sem_impl.h> 파일에 정의되어 있다.
    struct sem          *sem_base;
    ushort_t            sem_nsems;      // 세마포어 집합의 세마포어 개수다.
    time_t              sem_otime;      // 세마포어 연산을 마지막으로 수행한 시각이다.
    int32_t             sem_pad1;
    time_t              sem_ctime;      // 세마포어의 접근 권한을 마지막으로 변경한 시각이다.
    int32_t             sem_pad2;
    int                 sem_binary;     // 세마포어의 종류를 나타내는 프래그다.
    long                sem_pad3[3];
};

struct sem {
    ushort_t            semval;         // 세마포어 값
    pid_t               sempid;         // 세마포어 연산을 마지막으로 수행한 프로세스 ID
    ushort_t            semncnt;        // 세마포어 값이 현재 값보다 증가하기를 기다리는 프로세스 수
    ushort_t            semzcnt;        // 세마포어 값이 0이 되기를 기다리는 프로세스 수
    kcondvar_t          semncnt_cv;
    kcondvar_t          semzcnt_cv;
};
