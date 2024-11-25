
#include "philo.h"

int	perform_eating(t_phil *phil)
{
	if (phil->id % 2)
	{
/* 		if (!acquire_fork(phil, phil->left, "left"))
			return (0);
		if (!acquire_fork(phil, phil->right, "right"))
			return (0); */
		if (!acquire_fork(phil, phil->left, phil->right))
			return (0);
		
	} 
	else
	{
/* 		if (phil->first_loop)
		{
			eat_time(phil, 10);
			phil->first_loop = 0;
		} */
/* 		if (!acquire_fork(phil, phil->right, "right"))
			return (0);
		if (!acquire_fork(phil, phil->left, "left"))
			return (0); */
		if (!acquire_fork(phil, phil->right, phil->left))
			return (0);
		
	}
	print(phil, "is eating");
	phil->time_rest = phil->time_die;
	eat_time(phil, phil->time_eat);
	release_fork(phil->left);
	print(phil, "released left fork");
	release_fork(phil->right);
	print(phil, "released right fork");
	return (1);
}

/* int	perform_eating(t_phil **phil)
{
	if ((*phil)->id % 2)
	{
		if (!acquire_fork(phil, (*phil)->right, "right"))
			return (0);
		if (!acquire_fork(phil, (*phil)->left, "left"))
			return (0);
	} 
	else
	{
		if ((*phil)->first_loop)
		{
			eat_time(phil, 10);
			(*phil)->first_loop = 0;
		}
		if (!acquire_fork(phil, (*phil)->right, "right"))
			return (0);
		if (!acquire_fork(phil, (*phil)->left, "left"))
			return (0);
	}
	print(phil, "is eating");
	(*phil)->time_rest = (*phil)->time_die;
	eat_time(phil, (*phil)->time_eat);
	release_fork((*phil)->left);
	release_fork((*phil)->right);
	return (1);
} */


int	eat_time(t_phil *phil, int time)
{
	int	start_time;

	start_time = get_current_time();
	// Adjust eating time if the remaining time is less
	if (phil->time_rest < time)
		time = phil->time_rest;

	// Wait for the specified time or until the philosopher dies
	while (get_elapsed_time(start_time) < time)
	{
		//printf("Time remaining: %d\n", phil->time_rest);
		if (has_philosopher_died(phil))
			return (0); // Stop if the philosopher has died
		usleep(1000); // Avoid busy-waiting
		// phil->time_rest--;
		// if (phil->time_rest <= 0)
		// {
		// 	handle_death(phil);
		// 	return (0); // Indicate failure if the philosopher dies
		// }
	}

	//Reduce the remaining time and check for death
	phil->time_rest -= time;
	if (phil->time_rest <= 0)
	{
		handle_death(phil);
		return (0); // Indicate failure if the philosopher dies
	}
	printf("%d finished eating in %d, %d\n", phil->id, get_elapsed_time((phil)->info->start_time), phil->time_rest);
	return (1); // Successfully completed eating time
}


/* int	acquire_fork(t_phil *phil, t_fork *fork, const char *side)
{
	(void)side;
	long long	start_time;

	start_time = get_current_time();
	while (get_elapsed_time(start_time) < phil->time_rest)
	{
		pthread_mutex_lock(&fork->lock);
		if (fork->free)
		{
			fork->free = 0;
			//print(phil, "has taken a fork");
			pthread_mutex_unlock(&fork->lock);
			print(phil, "has taken a fork");
			phil->time_rest -= get_elapsed_time(start_time);
			return (1);
		}
		pthread_mutex_unlock(&fork->lock);

		if (has_philosopher_died(phil))
			return (0);

		//usleep(1000); // Avoid busy-waiting
	}

	handle_death(phil);
	return (0);
} */

int	acquire_fork(t_phil *phil, t_fork *fork_1, t_fork *fork_2)
{
	long long	start_time;
		start_time = get_current_time();
	while (get_elapsed_time(start_time) < phil->time_rest)
	{
		pthread_mutex_lock(&fork_1->lock);
		pthread_mutex_lock(&fork_2->lock);
		if ((fork_1->free) && (fork_2->free))
		{
			fork_1->free = 0;
			fork_2->free = 0;
			//print(phil, "has taken a fork");
			pthread_mutex_unlock(&fork_1->lock);
			pthread_mutex_unlock(&fork_2->lock);
			print(phil, "has taken a fork");
			print(phil, "has taken a fork");
			phil->time_rest -= get_elapsed_time(start_time);
			return (1);
		}
		pthread_mutex_unlock(&fork_1->lock);
		pthread_mutex_unlock(&fork_2->lock);

		if (has_philosopher_died(phil))
			return (0);

		//usleep(1000); // Avoid busy-waiting
	}

	handle_death(phil);
	return (0);
}
/* void release_fork(t_phil *phil, t_fork *fork, const char *side)
{
	pthread_mutex_lock(&fork->lock);
	fork->free = 1;
	pthread_mutex_unlock(&fork->lock);
}
 */

void	release_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->lock);
	fork->free = 1;
	pthread_mutex_unlock(&fork->lock);
}

