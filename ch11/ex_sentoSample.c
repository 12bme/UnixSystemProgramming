char *msg = "Send Test\n";
int len = strlen(msg) + 1;
struct sockaddr_in sin;
int size = sizeof(struct sockaddr_in);

memset((char *)&sin, '\0', sizeof(sin));
sin.sin_family = AF_INET;
sin.sin_port = htons(9000);
sin.sin_addr.s_addr = inet_addr("192.168.10.1");
memset(&(sin.sin_zero), 0, 8);

if(sendto(sd, msg, len, 0, (struct sockaddr *)&sin, size) == -1) {
    perror("sendto");
    exit(1);
}
