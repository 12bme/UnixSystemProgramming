#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int fd[2];
    pid_t pid;

    if(pipe(fd) == -1) {  // 파이프를 생성한다.
        perror("pipe");
        exit(1);
    }

    // fork 함수를 사용해 자식 프로세스를 생성한다. pas 명령의 결과는
    // 기본으로 표준 출력으로 출력되고, grep 명령은 표준 입력을 통해
    // 입력받는다. 따라서 부모 프로세스와 자식 프로세스 간의 통신이
    // 표준 입출력 대신 파이프를 통해 이루어지도록 만들어야 한다.
    switch(pid = fork()) {
        case -1:
            perror("fork");
            exit(1);
            break;
        case 0: /* child */
            // 자식 프로세스가 해야 할 일은 부모 프로세스가 파이프로 출력하는
            // ps -ef 명령의 결과를 받아 grep telnet 명령을 수행하는 것이다.
            // 따라서 파이프의 출력 부분이 필요없으므로 fd[1]을 닫는다.
            close(fd[1]); // 읽기용으로 사용
            // fd[0]의 값이 0이 아니면, 즉 표준 입력이 아니면 fd[0]의 값을
            // 표준 입력으로 복사 한 후 fd[0]을 닫느다. 이제 자식 프로세스에서는
            // 표준 입력을 fd[0]이 가리키는 파이프에서 읽는다.
            if(fd[0] != 0) {
                dup2(fd[0], 0);
                close(fd[0]);
            }
            // 자식 프로세스가 grep 명령을 exec 함수로 호출한다. 이렇게 하면 grep 명령은
            // 표준 입력을 통해 데이터를 읽어들이려 한다. 이미 위쪽에 표준 입력으로 파이프의
            // 입력 파일 기술자를 복사했으므로 결과적으로 파이프를 통해 데이터를 읽어들인다.
            execlp("grep", "grep", "telnet", (char *)NULL);
            exit(1);
            break;
        default:
            // 부모 프로세스의 동작을 살펴보면 자식 프로세스와 크게 다를 것이 없음을 알 수 있다.
            // 우선 파이프의 입력 부분이 필요 없으므로 닫느다.
            close(fd[0]);
            // 파이프의 출력 부분을 표준 출력으로 복사한다. 따라서 부모 프로세스에서
            // 무언가를 출력하면, 파이프를 통해 출력된다.
            if(fd[1] != 1) {
                dup2(fd[1], 1);
                close(fd[1]);
            }
            // exec 함수를 사용해 ps -ef 명령을 실행한다. ps -ef의 명령은 기본으로 표준 출력으로
            // 출력하므로 결과가 파이프로 출력된다. 이 출력 결과를 자식 프로세스가 읽어 들인다.
            execlp("ps", "ps", "-ef", (char *)NULL);
            wait(NULL);
            break;
    }

    return 0;
}
