/* Starter code for the echo exercise.
Loosely based on the example in Head First C Chapter 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void parent_code(int pipe_to_child[],int pipe_from_child[])
{
    // close the read end of pipe to child
    close(pipe_to_child[0]);
    close(pipe_from_child[1]);

    int count = 128;
    char buffer[count];

    // write a string to the child
    char line[] = "I'm proud of you, child.";
    ssize_t size = write(pipe_to_child[1], line, strlen(line)+1);
    if (size == -1)
        error("Parent can't write to child");
    printf("Parent wrote %ld bytes\n", size);
    size = read(pipe_from_child[0], buffer, count);
    if (size == -1)
        error("Parent can't read from child");
    printf("Parent read %ld bytes.\n", size);
    printf("Parent read: %s\n", buffer);
}


void child_code(int pipe_to_child[],int pipe_from_child[])
{
    // close the write end of pipe to child
    close(pipe_to_child[1]);
    close(pipe_from_child[0]);

    int count = 128;
    char buffer[count];

    // read from pipe_to_child
    ssize_t size = read(pipe_to_child[0], buffer, count);
    if (size == -1)
        error("Child can't read from parent");
    printf("Child read %ld bytes.\n", size);
    printf("Child read: %s\n", buffer);
    char line[] = "Thank you, father.";
    size = write(pipe_from_child[1], line, strlen(line)+1);
    if (size == -1)
        error("Child can't write to parent");
    printf("Child wrote %ld bytes\n", size);

    exit(0);
}


int main(int argc, char *argv[])
{
    /*Create a pipe */
    int pipe_to_child[2];
    int pipe_from_child[2];
    if (pipe(pipe_to_child) == -1)
        error("Can't create the first pipe");
    if (pipe(pipe_from_child) == -1)
        error("Can't create the second pipe");

    /*Fork a child process*/
    pid_t child_pid = fork();
    if (child_pid == -1)
        error("Can't fork process");

    if (child_pid == 0) {
        child_code(pipe_to_child,pipe_from_child);
    } else {
        parent_code(pipe_to_child,pipe_from_child);
    }

    int status;
    pid_t pid = wait(&status);
    if (pid == -1) {
        error("Error waiting for child process");
    }
    printf("Child %d exited with code %d\n", pid, status);
}
