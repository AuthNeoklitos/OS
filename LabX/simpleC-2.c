#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
int p[2];
pid_t pid;
char window[40];
char message[] = "This message will be in the pipe";

if( pipe(p) == -1){
	perror("pipe");
	return 1;
}
pid = fork();

if (pid == -1){
	perror("fork");
	exit(EXIT_FAILURE);
}
else if (pid == 0){
// child proccess
close(p[1]); //it bugs my cl if i dont add these 
read(p[0], window, sizeof(window));
printf("The inside of pipe says: %s \n", window);
close(p[0]);
}
else {
// parent proccess
close(p[0]);
write(p[1], message, strlen(message) + 1);
close(p[1]);
}

return 0;
}
