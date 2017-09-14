int sd;
struct sockaddr_in sin;

memset((char *)&sin, '\0', sizeof(sin));
sin.sin_family = AF_INET;
sin.sin_port = htons(9000);
sin.sin_addr.s_addr = inet_addr("192.168.100.1");
memset(&(sin.sin_zero), 0, 8);

connect(sd, (struct sockaddr *)&sin, sizeof(struct sockaddr));
