/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:21:40 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/13 09:09:46 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*all_alive_check(void *data_p)
{
	int	i;
	t_data	*data;
	t_philo	*philos;

	data = (t_data *)data_p;
	philos = data->philos;
	i = 0;
	while (true)
	{
		if (get_time() - philos[i].last_eat_time > data->die_time)
		{
			change_philo_state(&philos[i], DEAD);
			pthread_mutex_lock(&data->mut_all_alive);
			data->all_alive = false;
			pthread_mutex_unlock(&data->mut_all_alive);
			break ;
		}
		i++;
		if (i == data->nb_philos)
			i = 0;
	}
	return (NULL);
}

void	sleep_if_id_even(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep((philo->sleep_time / 2) * 1000);
}

bool	all_alive_and_full_check(t_data *data)
{
	bool	result;

	result = true;
	pthread_mutex_lock(&data->mut_all_alive);
	if (data->all_alive == false)
		result = false;
	pthread_mutex_unlock(&data->mut_all_alive);
	if (result == true)
	{
		pthread_mutex_lock(&data->mut_nb_full_p);
		if (data->nb_full_p >= data->nb_meals)
			result = false;
		pthread_mutex_unlock(&data->mut_nb_full_p);
	}
	return (result);
}

void	*routine(void *philo_p)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *) philo_p;
	data = philo->data;

	sleep_if_id_even(philo);
	while (true)
	{
		if (!all_alive_and_full_check(philo->data))
			break ;
		eat(philo);
		if (!all_alive_and_full_check(philo->data))
			break ;
		ft_sleep(philo);
		if (!all_alive_and_full_check(philo->data))
			break ;
		think(philo); 
	}
	return (NULL);
}
