/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:59:48 by avarghes          #+#    #+#             */
/*   Updated: 2024/11/26 02:59:51 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_death(t_phil *phil)
{
	pthread_mutex_lock(&phil->info->lock);
	if (!phil->info->death)
		phil->info->death = 1;
	pthread_mutex_unlock(&phil->info->lock);
	print(phil, "died");
	phil->time_rest = 0;
}

int	has_philosopher_died(t_phil *phil)
{
	int	is_dead;

	pthread_mutex_lock(&phil->info->lock);
	is_dead = phil->info->death;
	pthread_mutex_unlock(&phil->info->lock);
	return (is_dead);
}
