#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    //file_descriptor - pointer to an array of two integers, where
    //file_descriptor[0] - file descriptor for output,
    //file_descriptor[1] - file descriptor for input.
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

    //trying to write the initial string into our pipe
    if(write(file_descriptor[1], s_in, sizeof(s_in)) != sizeof(s_in)){
        printf("Cannot write the string into the pipe:("); 
        exit(-1); 
    }

    //trying to read sizeof(s_in) bytes from our pipe and save it to s_out
    if(read(file_descriptor[0], s_out, sizeof(s_in)) < 0){
        printf("Cannot read the string from the pipe:("); 
        exit(-1); 
    } 
    printf("Transferred string: %s\n", s_out);

    //closing reading and writing
    close(file_descriptor[0]);
    close(file_descriptor[1]);
    return 0; 
}

/* 

-- Output --

Transferred string: OS is the best course ever

*/