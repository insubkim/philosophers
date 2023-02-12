#include <stdio.h>
#include <unistd.h>

#include <sys/time.h>

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return ((long long)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}


int main()
{
    long long t = 5000000;
    long long s = get_time();
    usleep(t *0.7);
    while (get_time() < s + t)
        ;
    printf("dobe\n");
}