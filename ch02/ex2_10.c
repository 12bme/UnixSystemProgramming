#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int cnt;

    // 리턴 결과값
    cnt = unlink("tmp.aaa");
    if(cnt == -1) {
        perror("Unlink tmp.aa");
        exit(1);
    }

    printf("Unlink tmp.aaa success!!!\n");

    return 0;
}
