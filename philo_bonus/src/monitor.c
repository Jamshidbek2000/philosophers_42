/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:16:41 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/02 13:48:42 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

bool	someone_died(void)
{
	sem_t	*death;

	death = sem_open("/death", AT_EACCESS, 0);
	if (death == SEM_FAILED)
		return (false);
	sem_close(death);
	return (true);
}

void	let_others_know(void)
{
	sem_open("/death", O_CREAT, 0644, 0);
}

bool	philo_died(t_data *data)
{
	if (get_philo_state(data) != EATING
		&& get_time() - get_last_eat_time(data) > data->die_time)
		return (true);
	return (false);
}

void	*monitor_death(void *data_p)
{
	t_data	*data;

	data = (t_data *)data_p;
	while (should_stop(get_philo_state(data)) == false)
	{
		if (someone_died())
			return (set_philo_state(data, FINISH), NULL);
		if (philo_died(data))
		{
			sem_wait(data->sem_print);
			if (philo_died(data) && someone_died() == false)
			{
				set_philo_state(data, DEAD);
				let_others_know();
				printf("%llu %d %s\n", get_time() - get_start_time(data),
					data->philo.id, DIED);
				sem_post(data->sem_print);
				break ;
			}
			sem_post(data->sem_print);
		}
		usleep(1000);
	}
	return (NULL);
}
	// sem_wait(data->sem_print);
	// printf("\t\t%d MONITOR EXITED\n", data->philo.id);
	// sem_post(data->sem_print);
