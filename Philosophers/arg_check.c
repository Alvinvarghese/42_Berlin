/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:59:32 by avarghes          #+#    #+#             */
/*   Updated: 2024/11/26 02:59:35 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_check(int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	if (argc < 5 || argc > 6)
		return (0);
	while (i < argc)
	{
		if (check_valid(argv[i]) == 0)
			return (0);
		num = ft_atoi(argv[i]);
		if (i == 1)
		{
			if (!(num > 0 && num <= 200))
				return (0);
		}
		else if ((i == 5 && num < 0) || (i != 5 && num <= 0))
			return (0);
		i++;
	}
	return (1);
}

int	check_valid(char *str)
{
	if (!check_digits(str))
		return (0);
	if (!check_int(str))
		return (0);
	return (1);
}

int	check_digits(char *str)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			return (0);
	}
	str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	check_int(char *str)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (num > INT_MAX / 10 || \
			(num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
			return (0);
		if (num < INT_MIN / 10 || \
			(num == INT_MIN / 10 && (str[i] - '0') > -(INT_MIN % 10)))
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}
