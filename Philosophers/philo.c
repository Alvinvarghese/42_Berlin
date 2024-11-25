
#include "philo.h"

/* int main(int argc, char **argv)
{
	if (arg_check(argc, argv) == 0)
	{
		printf("Error\n");
		return (1);
	}
	printf("Current time: %d\n", get_current_time());
	return (0);
} */

int	main(int argc, char **argv)
{
	int			n;
	t_info		*info;
	t_fork		*forks;
	t_phil		*phils;
	pthread_t	*threads;

	// Validate arguments
	if (!arg_check(argc, argv))
		return 0;

	info = NULL;
	forks = NULL;
	phils = NULL;
	threads = NULL;
	n = ft_atoi(argv[1]);

	// Setup resources
	if (!initialize_info(&info) ||
		!initialize_forks(&forks, n) ||
		!initialize_philosophers(&phils, argc, argv) ||
		!assign_philosopher_resources(&phils, &info, &forks, n) ||
		!initialize_threads(&threads, n))
	{
		cleanup_resources(info, forks, phils, threads);
		return 1;
	}
	// Start simulation
	printf("Synchronization of Threads\n");
	create_threads(threads, n, phils);
	join_threads(threads, n);

	// Cleanup resources
	cleanup_resources(info, forks, phils, threads);

	return 0;
}
