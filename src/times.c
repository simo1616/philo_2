#include "philo.h"

uint64_t get_time(void)
{
    struct timeval t;

    if(gettimeofday(&t, NULL))
	{
		error("gettimeofday() FAILED!\n");
		return(-1);
	}
    return((t.tv_sec * (uint64_t)1000) + (t.tv_usec / 1000));
}

uint64_t get_cur_time(uint64_t start_time)
{
	uint64_t cur_time;

	cur_time = get_time();
	// printf("\nstart_time: %lu\n", start_time);
	// printf("\ncur_time: %lu\n", cur_time);
	// printf("\n------------\nTIME return: %lu\n-------------\n", cur_time - start_time);
	return (cur_time - start_time);
}
