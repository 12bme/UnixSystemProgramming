struct timeval timeout;
timeout.tv_sec = atol(argv[1]);
timeout.tv_usec = atol(argv[2]);

if(select(0, (fd_set *)0, (fd_set *)0, &timeout) < 0) {
    printf("select error\r\n");
    return FALSE;
}
return TRUE;
