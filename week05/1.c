#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

void *thread_funct(void *i) {
	printf("Thread %d has ID %d.\n", *(int*)i, (int) pthread_self()); 
    pthread_exit(NULL);
}

int main() {
    for (int i = 0; i < N; i++) {
        pthread_t tid;
        pthread_create(&tid, NULL, thread_funct, (void*)&i);
        printf("Thread %d created.\n", i);
        pthread_join(tid, NULL);
    }
    printf("Finish.");
  	return 0;
}

/*   Output
--Before fixing--
--execution in a chaotic manner--
Thread 0 created.
Thread 1 created.
Thread 2 created.
Thread 2 has ID 187555840.
Thread 3 created.
Thread 1 has ID 187019264.
Thread 4 has ID 188628992.
Thread 3 has ID 188092416.
Thread 4 has ID 189165568.
Thread 4 created.
Thread 5 created.
Thread 6 created.
Thread 7 created.
Thread 7 has ID 190238720.
Thread 7 has ID 189702144.
Thread 8 created.
Thread 8 has ID 190775296.
Thread 9 created.
Finish.
Thread 8 has ID 191311872.
Thread 0 has ID 191848448.



--After fixing--
Thread 0 created.
Thread 0 has ID 130035712.
Thread 1 created.
Thread 1 has ID 130035712.
Thread 2 created.
Thread 2 has ID 130035712.
Thread 3 created.
Thread 3 has ID 130035712.
Thread 4 created.
Thread 4 has ID 130035712.
Thread 5 created.
Thread 5 has ID 130035712.
Thread 6 created.
Thread 6 has ID 130035712.
Thread 7 created.
Thread 7 has ID 130035712.
Thread 8 created.
Thread 8 has ID 130035712.
Thread 9 created.
Thread 9 has ID 130035712.
Finish.
*/