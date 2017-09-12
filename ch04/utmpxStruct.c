struct utmpx {
    char    ut_user[32];
    char    ut_id[4];
    char    ut_line[32];
    pid_t   ut_pid;
    short   ut_type;
    struct  exit_status ut_exit;
    struct  timeval ut_tv;
    int     ut_session;
    int     pad[5];
    short   ut_syslen;

    char    ut_host[257];

};
