/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:31:54 by avarghes          #+#    #+#             */
/*   Updated: 2024/11/26 03:34:26 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_phil	*phil;
	int		eat_count;

	phil = (t_phil *)arg;
	eat_count = 0;
	while (0 < (phil->info->start_time - get_current_time()))
	{
		usleep(100);
	}
	while (phil->n_eat == -1 || eat_count < phil->n_eat)
	{
		perform_thinking(phil);
		if (!perform_eating(phil))
			break ;
		if (!perform_sleeping(phil))
			break ;
		eat_count++;
	}
	return (NULL);
}
