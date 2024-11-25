
#include "philo.h"

int	initialize_info(t_info **info)
{
	*info = malloc(sizeof(t_info));
	if (!(*info))
		return (0);
	
	(*info)->print = 1;
	(*info)->death = 0;
	(*info)->ready = 0;
	pthread_mutex_init(&(*info)->lock, NULL);
	pthread_mutex_init(&(*info)->start_mutex, NULL);
	(*info)->start_time = get_current_time();
	return (1);
}

void	philo_info_free(t_info **info)
{
	pthread_mutex_destroy(&(*info)->lock);
	free(*info);
	*info = NULL;
}