char buf[80];
int len, rlen;

if((rlen = recv(sd, buf, len, 0)) == -1) {
    perror("recv");
    exit(1);
}
