/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:20:54 by avarghes          #+#    #+#             */
/*   Updated: 2024/11/26 03:21:03 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize_info(t_info **info)
{
	*info = malloc(sizeof(t_info));
	if (!(*info))
		return (0);
	memset(*info, 0, sizeof(t_info));
	(*info)->print = 1;
	pthread_mutex_init(&(*info)->lock, NULL);
	pthread_mutex_init(&(*info)->start_mutex, NULL);
	pthread_mutex_init(&(*info)->starving_mutex, NULL);
	(*info)->start_time = get_current_time();
	return (1);
}

void	philo_info_free(t_info **info)
{
	pthread_mutex_destroy(&(*info)->lock);
	pthread_mutex_destroy(&(*info)->start_mutex);
	pthread_mutex_destroy(&(*info)->starving_mutex);
	free(*info);
	*info = NULL;
}
