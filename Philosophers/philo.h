/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:31:39 by avarghes          #+#    #+#             */
/*   Updated: 2024/11/26 03:31:42 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>                      // printf
# include <stdlib.h>                 // exit
# include <unistd.h>             // usleep
# include <pthread.h>        // pthread_create, pthread_join
# include <sys/time.h>     // gettimeofday
# include <limits.h>
# include <string.h>

typedef struct s_info
{
	int				print;
	int				death;
	int				ready;
	int				phil_starving[200];
	pthread_mutex_t	lock;
	pthread_mutex_t	start_mutex;
	pthread_mutex_t	starving_mutex;
	long			start_time;
}	t_info;

typedef struct s_fork
{
	int				free;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_phil
{
	int				n;
	int				id;
	int				first_loop;
	int				n_eat;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_rest;
	int				is_starving;
	t_fork			*left;
	t_fork			*right;
	t_info			*info;
}	t_phil;

/*	arg_check.c */
int		arg_check(int argc, char **argv);
int		check_valid(char *str);
int		check_digits(char *str);
int		check_int(char *str);
/* int		ft_atoi(const char *str);
int		is_digit(char *str); */

/*	fork.c */
int		initialize_forks(t_fork **fork, int num);
void	fork_free(t_fork **fork, int num);

/*	philo_info.c */
int		initialize_info(t_info **info);
void	philo_info_free(t_info **info);

/*	philo_intialize.c */
int		initialize_philosophers(t_phil **phils, int argc, char **argv);
int		assign_philosopher_resources(t_phil **phils, t_info **info, \
		t_fork **forks, int total);
void	cleanup_philosophers(t_phil **phils);

/*	threads.c */
int		initialize_threads(pthread_t **threads, int count);
void	create_threads(pthread_t *threads, int count, t_phil *phils);
void	join_threads(pthread_t *threads, int count);
void	deallocate_threads(pthread_t **threads);

/*	routine.c*/
void	*routine(void *arg);

/*	eat.c */
int		perform_eating(t_phil *phil);
int		eat_time(t_phil *phil, int time);
int		check_starving(t_phil *phil);
void	release_fork(t_fork *fork);

/*	acquire_fork.c */
int		acquire_fork(t_phil *phil, t_fork *fork_1, t_fork *fork_2);

/*	die.c */
void	handle_death(t_phil *phil);
int		has_philosopher_died(t_phil *phil);

/*	sleep_think.c */
int		perform_sleeping(t_phil *phil);
void	perform_thinking(t_phil *phil);

/*	cleanup_resources.c */
void	cleanup_resources(t_info *info, t_fork *forks, t_phil *phils, \
		pthread_t *threads);

/*	philo.c */
int		main(int argc, char **argv);

/*	util.c */
int		ft_atoi(const char *str);
int		get_current_time(void);
int		get_elapsed_time(int start_time);

/*	print.c */
void	print(t_phil *phil, const char *message);

#endif