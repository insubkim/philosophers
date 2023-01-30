#include "philosophers.h"

int l;

void    *run(void *a)
{
    pthread_mutex_t *b;

    b = (pthread_mutex_t *)a;
    while (1){
    //pthread_mutex_lock(b);
    
        pthread_mutex_lock(b);
        l++;
        pthread_mutex_unlock(b);
    }
    b++;
    return 0;
}

int main()
{
pthread_mutex_t a;

         pthread_mutex_init(&a, 0);
     pthread_t k[500];
     int i = 0;
     while (i < 100)
     {pthread_create(&k[i], 0, run, &a);
     i++;
     }
    // void *i;
    // pthread_join(k[0], &i);
    // pthread_join(k[1], &i);
  
    while (1)
    {  
        
        printf("%llu\n",micro_get_time());
    }
}