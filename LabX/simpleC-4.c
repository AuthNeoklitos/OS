#include <stdio.h>
#include <unistd.h>

int main() {
    FILE *file = fopen("pid_file.txt", "w");

    if (!file) {
        perror("fopen");
        return 1;
    }

    pid_t pid = fork();

    if( pid == -1){
    perror("fork");
}
    else  if (pid == 0) {
        // Child process
        fprintf(file, "Child PID: %d\n", getpid());
    } else {
        // Parent process
        fprintf(file, "Parent PID: %d\n", getpid());
    }

    fclose(file);
    return 0;
}
