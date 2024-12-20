#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 

int main() {
	printf("Parent pid = %d \n", getpid());
	for(int i=0; i<3; i++){
	pid_t p = fork();

		if (p == 0){
		// childs do this only
		printf("Child pid = %d \n", getpid());
		return 0;
		}
	
	}

	return 0;



}
