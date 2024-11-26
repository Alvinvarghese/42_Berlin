/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acquire_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:14:30 by avarghes          #+#    #+#             */
/*   Updated: 2024/11/26 03:14:32 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	try_acquire_forks(t_fork *fork_1, t_fork *fork_2)
{
	pthread_mutex_lock(&fork_1->lock);
	if (!fork_1->free)
	{
		pthread_mutex_unlock(&fork_1->lock);
		return (0);
	}
	pthread_mutex_lock(&fork_2->lock);
	if (!fork_2->free)
	{
		pthread_mutex_unlock(&fork_2->lock);
		pthread_mutex_unlock(&fork_1->lock);
		return (0);
	}
	fork_1->free = 0;
	fork_2->free = 0;
	pthread_mutex_unlock(&fork_1->lock);
	pthread_mutex_unlock(&fork_2->lock);
	return (1);
}

static int	handle_fork_acquisition(t_phil *phil, t_fork *fork_1, \
								t_fork *fork_2, long long *start_time)
{
	if (try_acquire_forks(fork_1, fork_2))
	{
		print(phil, "has taken a fork");
		print(phil, "has taken a fork");
		phil->time_rest -= get_elapsed_time(*start_time);
		return (1);
	}
	usleep(1000);
	return (0);
}

static int	process_starving_state(t_phil *phil, long long *start_time)
{
	int	any_starving;

	any_starving = check_starving(phil);
	if (!any_starving || phil->is_starving)
	{
		phil->time_rest -= get_elapsed_time(*start_time);
		*start_time = get_current_time();
		if (has_philosopher_died(phil))
			return (0);
		return (1);
	}
	phil->time_rest -= get_elapsed_time(*start_time);
	*start_time = get_current_time();
	return (2);
}

int	acquire_fork(t_phil *phil, t_fork *fork_1, t_fork *fork_2)
{
	long long	start_time;
	int			starving_status;

	start_time = get_current_time();
	if (fork_1 == fork_2)
	{
		while (get_elapsed_time(start_time) < phil->time_rest)
			usleep(1000);
	}
	else
	{
		while (get_elapsed_time(start_time) < phil->time_rest)
		{
			starving_status = process_starving_state(phil, &start_time);
			if (starving_status == 0)
				return (0);
			if (starving_status == 1)
			{
				if (handle_fork_acquisition(phil, fork_1, fork_2, &start_time))
					return (1);
			}
		}
	}
	handle_death(phil);
	return (0);
}
