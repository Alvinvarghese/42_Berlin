/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mssg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:01:20 by avarghes          #+#    #+#             */
/*   Updated: 2024/11/26 03:02:01 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_phil *phil, const char *message)
{
	t_info	*info;

	info = (phil)->info;
	pthread_mutex_lock(&info->lock);
	if (info->print)
	{
		printf(
			"%d %d %s\n",
			get_elapsed_time((phil)->info->start_time),
			(phil)->id,
			message);
		if (message[0] == 'd')
			info->print = 0;
	}
	pthread_mutex_unlock(&info->lock);
}
