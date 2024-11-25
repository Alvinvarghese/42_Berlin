/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_resources.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:37:15 by avarghes          #+#    #+#             */
/*   Updated: 2024/11/25 00:43:37 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_resources(t_info *info, t_fork *forks, t_phil *phils, \
							pthread_t *threads)
{
	if (forks)
		fork_free(&forks, phils->n);
	if (phils)
		cleanup_philosophers(&phils);
	if (threads)
		deallocate_threads(&threads);
	if (info)
		philo_info_free(&info);
}
