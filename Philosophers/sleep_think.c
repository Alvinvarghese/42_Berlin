/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:34:50 by avarghes          #+#    #+#             */
/*   Updated: 2024/11/26 03:36:05 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	perform_sleeping(t_phil *phil)
{
	print(phil, "is sleeping");
	if (!eat_time(phil, phil->time_sleep))
		return (0);
	return (1);
}

void	perform_thinking(t_phil *phil)
{
	print(phil, "is thinking");
}
