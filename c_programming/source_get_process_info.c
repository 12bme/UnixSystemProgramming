int get_process_info()
{
    PROC_LIST_T proc_list;
    // ... ... ...
    rc = SQLExecDirect(hStmt, (SQLCHAR *)"select process_id, desc, ... order by process_id asc", SQL_NTS);
    rc = SQLBindCol(&proc_list.proc_name, sizeof(proc_list.proc_name),
                    &l_status);
    // ... ... ...
    while((rc=SQLFetch(hStmt)) != SQL_NO_DATA_FOUND)
    {
        if(rc != SQL_SUCCESS) return -1;
        strcpy(proc_list.proc_name, "proc-name");
        strcpy(proc_list.proc_desc, "proc-desc");
        strcpy(proc_list.proc_alive, "proc-alive");
        strcpy(proc_list.proc_start_time, "proc-start-time");
        strcpy(proc_list.proc_stop_time, "proc-stop-time");
    }
    if(rc != SQL_SUCCESS) return -1;
    return SQL_SUCCESS;
}
