
#include "philo.h"


int	initialize_forks(t_fork **fork, int num)
{
	int	i;

	*fork = malloc(sizeof(t_fork) * num);
	if (!(*fork))
		return (0);
	i = 0;
	while (i < num)
	{
		pthread_mutex_init(&(*fork)[i].lock, NULL);
		(*fork)[i].free = 1;
		i++;
	}
	return (1);
}

void	fork_free(t_fork **fork, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(&(*fork)[i].lock);
		i++;
	}
	free(*fork);
	*fork = NULL;
}