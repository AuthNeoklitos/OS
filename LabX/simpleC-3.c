#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int sig) {
	printf("Child received signal: %d \n", sig);

}

int main(){
	pid_t pid = fork();
	if( pid==0 ){
		signal(SIGUSR1, handle_signal);
		pause(); // continues only after a signal is received
	}else {
		sleep(1); //neccesary for child to be ready // waits for only a second
		kill(pid, SIGUSR1);
	}
	return 0;

}
