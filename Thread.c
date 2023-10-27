#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 25

int thread_routine (int x){
    printf("I'm thread %2d my TID is %u\n",x,pthread_self());
    pthread_exit(0);
}

int main(){
    pthread_attr_t thread_attr;
    pthread_t tids [NUM_THREADS];
    int x;
    pthread_attr_init(&thread_attr);
    for(x = 0; x < NUM_THREADS; x++){
        pthread_create(&tids[x],&thread_attr,(void *)thread_routine,(void *) x);

    }

    printf("Waiting fro a thread fro threads tp finish\n");
    for(x = 0; x < NUM_THREADS; x++){

        pthread_join(tids[x], NULL);
    }

    printf("ALL threads are now finished\n");
}
 