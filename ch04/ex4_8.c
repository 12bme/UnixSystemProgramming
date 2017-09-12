#include <pwd.h>

int main(void) {
    struct passwd *pw;

    pw = getpwnam("testUser");
    printf("UID : %d\n", (int)pw->pw_uid);
    printf("Home Directory : %s\n", pw->pw_dir);

    return 0;
}
