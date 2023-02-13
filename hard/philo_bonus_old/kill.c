#include <semaphore.h>
int main()
{
    sem_unlink("fork");

    sem_unlink("write");

    sem_unlink("scheduler");
}