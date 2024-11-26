/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:07:50 by avarghes          #+#    #+#             */
/*   Updated: 2024/11/26 03:16:56 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_starving(t_phil *phil)
{
	t_info	*info;
	int		any_starving;
	int		i;

	i = 0;
	info = (phil)->info;
	any_starving = 0;
	pthread_mutex_lock(&info->starving_mutex);
	if (phil->time_rest <= (phil->time_eat + (phil->time_sleep / 2)))
	{
		info->phil_starving[phil->id - 1] = 1;
		phil->is_starving = 1;
	}
	while (i < phil->n)
	{
		if (info->phil_starving[i])
		{
			any_starving = 1;
			break ;
		}
		i++;
	}
	pthread_mutex_unlock(&info->starving_mutex);
	return (any_starving);
}

int	perform_eating(t_phil *phil)
{
	if (phil->id % 2)
	{
		if (!acquire_fork(phil, phil->left, phil->right))
			return (0);
	}
	else
	{
		if (!acquire_fork(phil, phil->right, phil->left))
			return (0);
	}
	print(phil, "is eating");
	phil->time_rest = phil->time_die;
	eat_time(phil, phil->time_eat);
	release_fork(phil->left);
	release_fork(phil->right);
	return (1);
}

int	eat_time(t_phil *phil, int time)
{
	int		start_time;
	t_info	*info;

	info = (phil)->info;
	phil->is_starving = 0;
	pthread_mutex_lock(&info->starving_mutex);
	phil->info->phil_starving[phil->id - 1] = 0;
	pthread_mutex_unlock(&info->starving_mutex);
	start_time = get_current_time();
	if (phil->time_rest < time)
		time = phil->time_rest;
	while (get_elapsed_time(start_time) < time)
	{
		if (has_philosopher_died(phil))
			return (0);
		usleep(1000);
	}
	phil->time_rest -= time;
	if (phil->time_rest <= 0)
	{
		handle_death(phil);
		return (0);
	}
	return (1);
}

/* int	acquire_fork(t_phil *phil, t_fork *fork_1, t_fork *fork_2)
{
	long long	start_time;
	int any_starving;

	start_time = get_current_time();

	if (fork_1== fork_2)
	{
		while (get_elapsed_time(start_time) < phil->time_rest)
		{
			usleep(1000);
		}
	}
	else
	{
		while (get_elapsed_time(start_time) < phil->time_rest)
		{
			any_starving = check_starving(phil);
			if (!any_starving || phil->is_starving)
			{
				phil->time_rest -= get_elapsed_time(start_time); 
				start_time = get_current_time(); 
				if (has_philosopher_died (phil)) 
					return (0);
			
				pthread_mutex_lock(&fork_1->lock);
				if (!fork_1->free)
				{
					pthread_mutex_unlock(&fork_1->lock); 
					usleep(1000);
					continue;
				}
				pthread_mutex_lock(&fork_2->lock);
				if (!fork_2->free)
				{
					pthread_mutex_unlock(&fork_2->lock);
					pthread_mutex_unlock(&fork_1->lock); 
					usleep(1000);
					continue;
				}
				fork_1->free = 0;
				fork_2->free = 0;
				pthread_mutex_unlock(&fork_1->lock);
				pthread_mutex_unlock(&fork_2->lock);
				print(phil, "has taken a fork");
				print(phil, "has taken a fork");
				phil->time_rest -= get_elapsed_time(start_time);
				return (1);
			}
			else
			{
				phil->time_rest -= get_elapsed_time(start_time);
				start_time = get_current_time();
			}
		}
	}
	handle_death(phil);
	return (0);
} */

// above code splitted by cody

void	release_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->lock);
	fork->free = 1;
	pthread_mutex_unlock(&fork->lock);
}
