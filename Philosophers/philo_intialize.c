
#include "philo.h"
#include <string.h>

static void	set_philosopher_attributes(t_phil *phil, int argc, char **argv, int id, int total)
{
	phil->n = total;
	phil->id = id + 1;
	phil->first_loop = 1;
	phil->time_die = ft_atoi(argv[2]);
	phil->time_eat = ft_atoi(argv[3]);
	phil->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		phil->n_eat = ft_atoi(argv[5]);
	else
		phil->n_eat = -1;
	phil->time_rest = phil->time_die;
}

int	initialize_philosophers(t_phil **phils, int argc, char **argv)
{
	int	i;
	int	total;

	total = ft_atoi(argv[1]);
	*phils = (t_phil *)malloc(sizeof(t_phil) * total);
	if (!*phils)
		return (0);
	memset(*phils, 0, sizeof(t_phil) * total);
	i = 0;
	while (i < total)
	{
		set_philosopher_attributes(&(*phils)[i], argc, argv, i, total);
		i++;
	}
	return (1);
}

/* void	assign_philosopher_resources(t_phil **phils, t_info **info, t_fork **forks, int total)
{
	int				i;
	pthread_mutex_t	*start_mutex;

	i = 0;
	start_mutex = &(*info)->start_mutex;
	pthread_mutex_init(start_mutex, NULL);
	pthread_mutex_lock(start_mutex);

	while (i < total)
	{
		(*phils)[i].left = &((*forks)[i]);
		(*phils)[i].right = &((*forks)[(i + 1) % total]);
		(*phils)[i].info = *info;
		(*phils)[i].info->start_time = get_time_current();
		i++;
	}
	pthread_mutex_unlock(start_mutex);
} */

int	assign_philosopher_resources(t_phil **phils, t_info **info, t_fork **forks, int total)
{
	int	i;

	i = 0;
	if (!phils || !info || !forks)
		return 0;
	while (i < total)
	{
		(*phils)[i].left = &((*forks)[i]);
		(*phils)[i].right = &((*forks)[(i + 1) % total]);
		(*phils)[i].info = *info;
		(*phils)[i].info->start_time = get_current_time();
		i++;
	}
	return (1); // Success
}


/* void	cleanup_philosophers(t_phil **phils)
{
	pthread_mutex_destroy(&(*phils)->info->start_mutex);
	free(*phils);
	*phils = NULL;
} */

void	cleanup_philosophers(t_phil **phils)
{
	if (phils && *phils)
	{
		free(*phils);
		*phils = NULL;
	}
}