/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:25:04 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/02 13:49:09 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

char	*create_sem_name(int id)
{
	return (ft_strjoin("/philo_", ft_itoa(id)));
}

int	set_philo(t_data *data, int id)
{
	char	*sem_name;

	sem_name = create_sem_name(id);
	if (sem_name == NULL)
		exit(MALLOC_ERROR);
	sem_unlink(sem_name);
	data->philo.sem_philo = sem_open(sem_name, O_CREAT, 0644, 1);
	sem_unlink(sem_name);
	free(sem_name);
	data->philo.id = id;
	update_last_meal_time(data);
	return (0);
}

void	sleep_if_id_is_even(t_data *data)
{
	if (data->philo.id % 2 == 0)
		ft_usleep(data->eat_time - 10);
}

bool	should_stop(t_state	state)
{
	if (state == DEAD)
		return (true);
	if (state == FINISH)
		return (true);
	if (state == FULL)
		return (true);
	return (false);
}

int	start_routine(t_data *data, int id)
{
	if (set_philo(data, id))
		exit(1);
	sleep_if_id_is_even(data);
	if (pthread_create(&data->monitor, NULL, &monitor_death, data))
		return (THREAD_ERROR);
	while (true)
	{
		if (eat(data) || should_stop(get_philo_state(data)))
		{
			break ;
		}
		if (ft_sleep(data) || should_stop(get_philo_state(data)))
		{
			break ;
		}
		if (think(data))
		{
			break ;
		}
	}
	if (pthread_join(data->monitor, NULL))
		exit(1);
	sem_close(data->philo.sem_philo);
	exit(0);
}
	// sem_wait(data->sem_print);
	// printf("\t\t%d EXITED\n", data->philo.id);
	// sem_post(data->sem_print);
