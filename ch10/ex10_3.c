#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    key_t key;
    int msgid;

    // 이전 예제와 같은 키를 생성해 메시지 큐 식별자를 리턴받는다.
    key = ftok("keyfile", 1);
    msgid = msgget(key, IPC_CREAT|0644);
    if(msgid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Before IPC_RMID\n");
    system("ipcs -q");
    // 메시지 큐 식별자를 IPC_RMID 명령으로 제거한다.
    msgctl(msgid, IPC_RMID, (struct msqid_ds *)NULL);
    printf("After IPC_RMID\n");
    system("ipcs -q");

    return 0;
}
