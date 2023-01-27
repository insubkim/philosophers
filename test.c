#include "philosophers.h"

int l;

void    *run(void *a)
{
    pthread_mutex_t *b;

    b = (pthread_mutex_t *)a;
    while (l < 10000){
    //pthread_mutex_lock(b);
    printf("i = %d\n", l++);
    //pthread_mutex_unlock(b);
    
    }
    b++;
    return 0;
}

int main()
{
    // pthread_mutex_t a;

    // pthread_mutex_init(&a, 0);
    // pthread_t k[2];
    // pthread_create(&k[0], 0, run, &a);
    // pthread_create(&k[1], 0, run, &a);
    // void *i;
    // pthread_join(k[0], &i);
    // pthread_join(k[1], &i);
    printf("hi\n");

    usleep(5000000);
    printf("bey\n");
    
}