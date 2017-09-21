int select(int nfds, fd_set *readfds,
        fd_set *writefds, fd_set * exceptfds, 
        struct timeval *timeout);
FD_ZERO(fd_set *set);
FD_SET(int fd, fd_set *fdset);
FD_CLR(int fd, fd_set *fdset);
FD_ISSET(int fd, fd_set *fdset);
