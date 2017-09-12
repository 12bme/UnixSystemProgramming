#include <sys/ucontext.h>
#include <unistd.h>
#include <signal.h>
#include <siginfo.h>
#include <stdlib.h>
#include <stdio.h>

void handler(int signo, siginfo_t *st, ucontext_t *uc) {
    psiginfo(sf, "Received Signal:"); // 시그널 핸들러 함수에서 psiginfo 함수를 호출해 시그널 정보를 출력한다.
    printf("si_code : %d\n", sf->si_code);
}

int main(void) {
    struct sigaction act;

    act.sa_flags = SA_SIGINFO; //SA_SIGINFO 플래그를 지정한다.
    act.sa_sigaction = (void (*)(int, siginfo_t *, void *))handler; // sa_handler 대신 sa_sigaction 멤버를 사용해 시그널 핸들러를 지정한다.
    sigemptyset(&act.sa_mask);
    if(sigaction(SIGUSR1, &act, (struct sigaction *)NULL) < 0) {   // SIGUSR1 시그널을 지정해 sigaction 함수로 시그널 처리를 등록한다.
        perror("sigaction");
        exit(1);
    }

    pause();

    return 0;
}
