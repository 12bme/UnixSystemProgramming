char *msg = "Sen Test\n";
int len = strlen(msg) + 1;

if(send(sd, msg, len, 0) == -1) {
    perror("send");
    exit(1);
}
