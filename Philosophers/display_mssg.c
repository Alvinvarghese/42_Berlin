#include "philo.h"

void	print(t_phil *phil, const char *message)
{
	t_info *info = (phil)->info;

	pthread_mutex_lock(&info->lock);
	if (info->print)
	{
		printf(
			"%d %d %s\n",
			get_elapsed_time((phil)->info->start_time),
			(phil)->id,
			message
		);
		// Disable further printing if the message indicates death
		if (message[0] == 'd')
			info->print = 0;
	}
	pthread_mutex_unlock(&info->lock);
}

/* 

void print(t_phil **phil, const char *message)
{
    t_info *info = (*phil)->info;

    pthread_mutex_lock(&info->lock);

    if (info->print)
    {
        printf(
            "%lld %d %s\n",
            get_time_elapsed((*phil)->time_start),
            (*phil)->id,
            message
        );

        // Disable further printing if the message indicates death
        if (message[0] == 'd')
            info->print = 0;
    }

    pthread_mutex_unlock(&info->lock);
}


 */