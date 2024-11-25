
#include "philo.h"

void	*routine(void *arg)
{
	t_phil	*phil;
	int		eat_count;

	phil = (t_phil *)arg;
	eat_count = 0;
	//fprintf(stderr, "\nThread %d started\n\n", phil->id);
	// Wait until the start time is reached
	//while (get_current_time() < phil->info->start_time)
	while (0 < (phil->info->start_time  - get_current_time()))
	{
		printf("Waiting for start time: %d\n", phil ->id);
		usleep(100);
	}
	while (phil->n_eat == -1 || eat_count < phil->n_eat)
	{
		perform_thinking(phil);
		if (!perform_eating(phil))
			break;
		if (!perform_sleeping(phil))
			break;
		//usleep(1000);
		eat_count++;
	}
	return (NULL);
}
