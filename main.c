#include <sys/types.h>
#include <stdio.h>  
#include <unistd.h> 
int main() {
    /*
     * Create a new process using fork().
     * fork() returns a pid_t value that tells us which process
     * we're running inside after the call:
     *   - 0      => we're in the child process
     *   - > 0    => we're in the parent process (value is child's PID)
     *   - -1     => fork failed (no child created)
     */
    pid_t pid = fork();

    if (pid == 0) {
        /* Child process branch.
         * getpid() returns the process ID of the calling process
         * (so here it returns the child's PID).
         */
        printf("This is the child process. PID: %d\n", getpid());
    }
    else if (pid > 0) {
        /* Parent process branch.
         * The parent receives the child's PID as fork()'s return value,
         * and getpid() here returns the parent's PID.
         */
        printf("This is the parent process. PID: %d\n", getpid());
    } 
    else {
        // fork failed 
        printf("Fork failed!\n");
    }
    return 0;
}