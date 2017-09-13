#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    key_t key;
    int shmid;

    key = ftok("shmfile", 1);   // ftok 함수를 사용해 키를 생성한다.
    shmid = shmget(key, 1024, IPC_CREAT|0644);  // shmget 함수를 사용해 공유 메모리를 생성한다.
    if(shmid == -1) {
        perror("shmget");
        exit(1);
    }

    return 0;
}
