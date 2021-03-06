#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// key: IPC_PRIVATE 또는 ftok 함수로 생성한 키
// size: 공유할 메모리의 크기
// shmflg: 공유 메모리의 속성을 지정하는 플래그
int shmget(key_t key, size_t size, int shmflg);
