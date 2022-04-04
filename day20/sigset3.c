#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void check_pending_sigs(sigset_t s)
{
    int i, res;
    sigprocmask(SIG_BLOCK, NULL, &s); // first param is not considered
    for (int i = 1; i < 5; i++)
    {
        res = sigismember(&s, i);
        if (res)
        {
            printf("signal %d is blocked\n", i);
        }
        else
        {
            printf("signal %d is not blocked\n", i);
        }
    }
}


void sighand(int signum){
    printf("i have to wake up him now\n");
}

int main()
{
    sigset_t s_set, s;
    signal(2, sighand);
    sigemptyset(&s_set);
    sigaddset(&s_set, 2);
    perror("sig2");
    sigprocmask(SIG_BLOCK | SIG_SETMASK, &s_set, NULL);
    perror("sigmask");
    printf("send me the signal one and see the effect now\n");
    getchar();
    getchar();
    sigpending(&s);
    check_pending_sigs(s);
    // check_blocked_signals(s);
    getchar();
    sigprocmask(SIG_UNBLOCK, &s_set, NULL);
    printf("now siganls are unblocked\n");
    while (1)
        ;
}