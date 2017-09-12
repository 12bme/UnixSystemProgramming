#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int fd, fd1;
    mode_t mode;

    mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    fd = open("tmp.aaa", O_CREAT | O_WRONLY | O_TRUNC, mode);
    
    if(fd == -1){
        perror("Create tmp.aaa");
        exit(1);
    }

    close(1);
    fd1 = dup(fd);

    printf("DUP FD=%d\n", fd1);
    printf("Standard Output Redirection\n");
    close(fd);

    return 0;
}
