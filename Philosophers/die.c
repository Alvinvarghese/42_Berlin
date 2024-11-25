
# include "philo.h"

void	handle_death(t_phil *phil)
{
	// Lock to ensure thread-safe access to shared resource
	pthread_mutex_lock(&phil->info->lock);
	if (!phil->info->death)
		phil->info->death = 1;
	pthread_mutex_unlock(&phil->info->lock);

	// Log the death event
	print(phil, "died");

	// Reset time_rest to 0 for proper cleanup
	phil->time_rest = 0;
}

int	has_philosopher_died(t_phil *phil)
{
	int	is_dead;

	// Lock to safely read the shared death flag
	pthread_mutex_lock(&phil->info->lock);
	is_dead = phil->info->death;
	pthread_mutex_unlock(&phil->info->lock);

	return (is_dead);
}
