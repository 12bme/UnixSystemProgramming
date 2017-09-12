#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    uid_t uid, euid;
    char *name, *cname;

    uid = getuid();
    euid = geteuid();

    name = getlogin();
    //cname = cuserid(NULL);

    printf("Login Name=%s, UID=%d, EUID=%d\n", name, (int)uid, (int)euid);

    return 0;
}
