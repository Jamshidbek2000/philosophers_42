/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:47:58 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/16 08:47:35 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

bool	is_philo_full(t_data *data, t_philo *philo)
{
	bool	result;

	result = false;
	if (get_nb_meals_philo_had(philo) >= data->nb_meals)
		result = true;
	return (result);
}

void	notify_all_philos(t_data *data)
{
	t_philo	*philos;
	int		i;
	int		nb_philos;

	nb_philos = get_nb_philos(data);
	philos = data->philos;
	i = -1;
	while (++i < nb_philos)
	{
		set_philo_state(&philos[i], DEAD);		
		pthread_mutex_lock(&data->mut_print);
		printf("\t\tnotified philo %d\n", philos[i].id);
		pthread_mutex_unlock(&data->mut_print);
	}
}

void	*all_full_routine(void *data_p)
{
	t_data	*data;
	int		i;
	int		nb_philos;

	
	data = (t_data *)data_p;
	i = -1;
	nb_philos = get_nb_philos(data);
	while (++i < nb_philos && get_keep_iter(data))
	{
		if (is_philo_full(data, &data->philos[i]) == false)
		{
			i = -1;
		}
	}
	if (get_keep_iter(data) == true)
	{
		set_keep_iterating(data, false);
		notify_all_philos(data);
	}
	print_mut(data, "all_full_routine exited");
	return (NULL);
}

void	*all_alive_routine(void *data_p)
{
	int		i;
	int		nb_philos;
	t_data	*data;
	t_philo	*philos;

	data = (t_data *)data_p;
	philos = data->philos;
	nb_philos = get_nb_philos(data);
	i = -1;
	while (++i < nb_philos)
	{
		if (get_philo_state(&philos[i]) == DEAD && get_keep_iter(data) == true)
		{
			set_keep_iterating(data, false);
			notify_all_philos(data);
			break ;
		}
		if (get_keep_iter(data) == false)
			break ;
		if (i == nb_philos - 1)
			i = -1;
	}
	print_mut(data, "all_alive_routine exited");
	return (NULL);
}


void	print_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mut_print);
	printf("\t\tID of dead %d\n", philo->id);
	pthread_mutex_unlock(&philo->data->mut_print);
}