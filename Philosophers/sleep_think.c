
# include "philo.h"

int perform_sleeping(t_phil *phil)
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