void dbFuncInit(void)
{
    int i;

    for(i=0; i<MAX_FUNC_NUM; i++)
        dbFuncMember[i] = NULL;

    DBFUNC(GET_PROCESS_INFO, get_process_info);
    DBFUNC(GET_ERROR_INFO, get_error_info);
    DBFUNC(GET_DISK_INFO, get_disk_info);
    DBFUNC(GET_CPU_INFO, get_cpu_info);
    DBFUNC(GET_DB_INFO, get_db_info);
    // ... ... ...
}
