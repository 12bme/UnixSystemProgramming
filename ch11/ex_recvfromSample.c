char buf[80];
int len, size;
struct sockaddr_in sin;

if(recvfrom(sd, buf, len, 0, (struct sockaddr *)&sin, &size) == -1) {
    perror("recvfrom");
    exit(1);
}
