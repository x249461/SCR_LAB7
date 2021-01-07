#include <pthread.h>
#include <stdio.h>

#define NTHREADS 5 

void *thread_func() {

    printf("Hello SCR. Written by thread %ld\n", pthread_self());
    
    pthread_exit(NULL);
}

int main(int arc, char *argv[]) {

    pthread_t id[NTHREADS];
    int error_code;

    for(int i = 0; i < NTHREADS; ++i) {

      error_code = pthread_create(&id[i], NULL, thread_func, NULL);

        if(error_code) {
            fprintf(stderr, "Thread was not properly created!");
        }
    }

    for(int i = 0; i < NTHREADS; ++i) {

        pthread_join(id[i], NULL);
    }

    pthread_exit(NULL);
} 
