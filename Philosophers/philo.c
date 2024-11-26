/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:26:49 by avarghes          #+#    #+#             */
/*   Updated: 2024/11/26 03:30:10 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int			n;
	t_info		*info;
	t_fork		*forks;
	t_phil		*phils;
	pthread_t	*threads;

	if (!arg_check(argc, argv))
		return (0);
	info = NULL;
	forks = NULL;
	phils = NULL;
	threads = NULL;
	n = ft_atoi(argv[1]);
	if (!initialize_info(&info) || !initialize_forks(&forks, n) || \
		!initialize_philosophers(&phils, argc, argv) || \
		!assign_philosopher_resources(&phils, &info, &forks, n) || \
		!initialize_threads(&threads, n))
	{
		cleanup_resources(info, forks, phils, threads);
		return (1);
	}
	create_threads(threads, n, phils);
	join_threads(threads, n);
	cleanup_resources(info, forks, phils, threads);
	return (0);
}
