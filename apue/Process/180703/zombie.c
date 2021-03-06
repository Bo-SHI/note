#include "apue.h"

#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid;

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid > 0) {
            exit(0);
        }

        printf("second child process, our parent process pid = %d\n", getppid());
        exit(0);
    } else {
        printf("main process, create child process: %d\n", pid);
    }

    if (waitpid(pid, NULL, 0) != pid) {
        err_sys("wait error");
    }

    exit(0);
}
