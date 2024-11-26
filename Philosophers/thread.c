/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:36:35 by avarghes          #+#    #+#             */
/*   Updated: 2024/11/26 03:36:38 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
The expression ::
				*threads != NULL evaluates to:

	1 (true) if *threads points to a valid memory address (not NULL).
	0 (false) if *threads is NULL.
*/

int	initialize_threads(pthread_t **threads, int count)
{
	*threads = (pthread_t *)malloc(sizeof(pthread_t) * count);
	return (*threads != NULL);
}

void	create_threads(pthread_t *threads, int count, t_phil *phils)
{
	int	index;

	index = 0;
	while (index < count)
	{
		pthread_create(&threads[index], NULL, routine, &phils[index]);
		index++;
	}
}

void	join_threads(pthread_t *threads, int count)
{
	int	index;

	index = 0;
	while (index < count)
	{
		pthread_join(threads[index], NULL);
		index++;
	}
}

void	deallocate_threads(pthread_t **threads)
{
	if (*threads)
	{
		free(*threads);
		*threads = NULL;
	}
}
