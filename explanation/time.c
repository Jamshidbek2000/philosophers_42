#include <stdio.h> // printf
#include <sys/time.h> // time
#include <stdint.h> // uint64_t
#include <unistd.h> // usleep

// struct timeval {
//     time_t      tv_sec;     // seconds
//     suseconds_t tv_usec;    // microseconds
// };

// int gettimeofday(struct timeval *tv, struct timezone *tz);

uint64_t	get_time(void) // returns time in milliseconds
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void    example_1()
{
    struct timeval time;

    gettimeofday(&time, NULL);
    printf("%ld seconds\n", time.tv_sec);
    printf("%ld macroseconds\n", time.tv_usec);

    printf("\n%ld years passed since 1970\n", time.tv_sec / 60 / 60 / 24 / 365);
}

void    example_2()
{
    uint64_t    start_time;
    uint64_t    now;

    start_time = get_time();
    usleep(10000); // accepts in microseconds
    now = get_time();
    printf("%ld milliseconds passed since the start\n", now - start_time);
}

int main()
{
    example_1();
    example_2();

    return (0);
}

