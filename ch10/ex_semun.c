union semun {
    int             val;
    struct semid_ds *buf;
    ushort_t        *array;
} arg;
