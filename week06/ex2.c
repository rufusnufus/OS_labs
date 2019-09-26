#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int file_descriptor[2];
    //our initial string
    char s_in[] = "OS is the best course ever";
    //empty string with the size of initial string
    char s_out[sizeof(s_in)];
    //trying to create a pipe
    if(pipe(file_descriptor) < 0){
        printf("Cannot create a pipe:(");
        exit(-1); 
    }
    if (fork() > 0) {
        close(file_descriptor[0]);
        //trying to write the initial string into our pipe
        if(write(file_descriptor[1], s_in, sizeof(s_in)) != sizeof(s_in)){
            printf("Cannot write the string into the pipe:("); 
            exit(-1); 
        }
        close(file_descriptor[1]);
        printf("Parent exit\n");
    } else {
        close(file_descriptor[1]);
        //trying to read sizeof(s_in) bytes from our pipe and save it to s_out
        if(read(file_descriptor[0], s_out, sizeof(s_in)) < 0){
            printf("Cannot read the string from the pipe:("); 
            exit(-1); 
        } 
        printf("Transferred string: %s\n", s_out);
        //closing reading and writing
        close(file_descriptor[0]);
        printf("Child exit\n");
    }    
    return 0; 
}

/*

-- Output --

Parent exit
Transferred string: OS is the best course ever
Child exit

*/