/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_intialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:22:16 by avarghes          #+#    #+#             */
/*   Updated: 2024/11/26 03:25:22 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_philosopher_attributes(t_phil *phil, int argc, \
						char **argv, int id)
{
	phil->n = ft_atoi(argv[1]);
	phil->id = id + 1;
	phil->first_loop = 1;
	phil->time_die = ft_atoi(argv[2]);
	phil->time_eat = ft_atoi(argv[3]);
	phil->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		phil->n_eat = ft_atoi(argv[5]);
	else
		phil->n_eat = -1;
	phil->time_rest = phil->time_die;
}

int	initialize_philosophers(t_phil **phils, int argc, char **argv)
{
	int	i;
	int	total;

	total = ft_atoi(argv[1]);
	*phils = (t_phil *)malloc(sizeof(t_phil) * total);
	if (!*phils)
		return (0);
	memset(*phils, 0, sizeof(t_phil) * total);
	i = 0;
	while (i < total)
	{
		set_philosopher_attributes(&(*phils)[i], argc, argv, i);
		i++;
	}
	return (1);
}

int	assign_philosopher_resources(t_phil **phils, t_info **info, \
									t_fork **forks, int total)
{
	int	i;

	i = 0;
	if (!phils || !info || !forks)
		return (0);
	while (i < total)
	{
		(*phils)[i].left = &((*forks)[i]);
		(*phils)[i].right = &((*forks)[(i + 1) % total]);
		(*phils)[i].info = *info;
		(*phils)[i].info->start_time = get_current_time();
		i++;
	}
	return (1);
}

void	cleanup_philosophers(t_phil **phils)
{
	if (phils && *phils)
	{
		free(*phils);
		*phils = NULL;
	}
}
