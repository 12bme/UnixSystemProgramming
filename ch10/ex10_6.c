#include <sys/types.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    key_t key;
    int shmid;
    void *shmaddr;
    char buf[1024];
 
    // talker는 listener와 같은 파일과 정수값을 사용해 키를 생성한다.
    key = ftok("shmfile", 1);
    // 키값으로 listenr가 만든 공유 메모리의 식별자를 읽어온다.
    shmid = shmget(key, 1024, 0);

    // 공유 메모리와 연결하고 해당 메모리에 인삿말을 복사한다.
    shmaddr = shmat(shmid, NULL, 0);
    strcpy(shmaddr, "Hello, I'm, talker\n");

    // 명령행 인자로 받은 listener의 PID를 지정하고 SIGUSR1 시그널을 보낸다.
    kill(atoi(argv[1]), SIGUSR1);
    // sleep 함수를 수행해 잠시 기다렸다가 공유 메모리에서 listener가 보낸 응답을 읽어 출력한다.
    sleep(2);
    strcpy(buf, shmaddr);

    printf("Listener said : %s\n", buf);

    // 현재 공유 메모리의 상태 정보를 검색한 후 , 공유메모리 연결을 해제하고
    system("ipcs -m");
    shmdt(shmaddr);
    // 공유메모리를 제거한다.
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
