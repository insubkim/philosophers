#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <limits.h>
int main()
{
    sem_t *s = sem_open("semm", O_CREAT, 777, 1);
    if (!s)
        printf("oo");
    sem_wait(s);
    printf("hi\n");
    sem_post(s);
    
    printf("bye\n");
}