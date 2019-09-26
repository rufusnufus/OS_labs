#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main(){
    //file_descriptor - pointer to an array of two integers, where
    //file_descriptor[0] - file descriptor for output,
    //file_descriptor[1] - file descriptor for input.
    int file_descriptor[2];

    //trying to create a pipe
    if(pipe(file_descriptor) < 0){
        printf("Cannot create a pipe:(");
        exit(-1); 
    }

    int this_pid = getpid(); //pid of parent
    int pid_child1 = fork(); //pid of 1st child
    int pid_child2 = fork(); //pid of 2nd child
    if(pid_child1 == 0){
        int pid_to_get;
        //waiting for pid of 2nd child
        while(read(file_descriptor[0], &pid_to_get, sizeof(pid_to_get)) < 0);
        
        printf("1st child: Received the pid of second child: %d. In 3 seconds it will be killed. Uahahaha!!!\n",  pid_to_get);
        sleep(3);

        kill(pid_to_get, SIGSTOP); //sends a sigstop to 2nd child
        printf("1st child: Now I'm a murder. No way, 2nd child is dead.\n");
        exit(1);
    }else if(pid_child2 == 0){
        while(1)
            {
                printf("2nd child: I'm alive:)\n");
                sleep(1);
            }
    }else{
        //writes the pid of 2nd child
        write(file_descriptor[1], &pid_child2, sizeof(pid_child2));  //writes pid to pipe
        printf("Parent: I signed the paper to kill my 2nd child. I wrote the pid of 2nd child...\n");
        int status;
        //waits for state changes in 2nd child
        pid_t t = waitpid(pid_child2-1, &status, 0);
        printf("Parent: 1st child died with status %d. That is the end.\n", status);
        exit(1);
    }

    //closing reading and writing
    close(file_descriptor[0]);
    close(file_descriptor[1]);
    return 0; 
}

/*
-- Output --

Parent: I signed the paper to kill my 2nd child. I wrote the pid of 2nd child...
1st child: Received the pid of second child: 2279. In 3 seconds it will be killed. Uahahaha!!!
2nd child: I'm alive:)
2nd child: I'm alive:)
2nd child: I'm alive:)
1st child: Now I'm a murder. No way, 2nd child is dead.
Parent: 1st child died with status 256. That is the end.

*/