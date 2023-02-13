/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:04:10 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/13 09:06:12 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// bool all_alive(t_data *data)
// {
// 	bool	result;

// 	result = true;
// 	pthread_mutex_lock(&data->mut_dead_p);
// 	if (data->nb_dead > 0)
// 		result = false;
// 	pthread_mutex_unlock(&data->mut_dead_p);
// 	return (result);
// }

// bool	all_full(t_data *data)
// {
// 	bool	result;

// 	result = false;
// 	pthread_mutex_lock(&data->mut_full_p);
// 	if (data->nb_full == data->nb_philos)
// 		result = true;
// 	pthread_mutex_unlock(&data->mut_full_p);
// 	return (result);
// }

void	change_philo_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->mut_state);
	philo->state = state;
	pthread_mutex_unlock(&philo->mut_state);
}

void	free_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		pthread_mutex_destroy(&data->philos[i].mut_state);
		pthread_mutex_destroy(&data->philos[i].mut_l_m_t);
	}
	pthread_mutex_destroy(&data->mut_all_alive);
	pthread_mutex_destroy(&data->mut_nb_full_p);
	pthread_mutex_destroy(&data->mut_nb_meals);
	pthread_mutex_destroy(&data->mut_print);
	
	free(data->philos);
	free(data->forks);
}

void	print_msg(t_data *data, int id, char *msg)
{
	uint64_t	time;

	time = get_time();
	pthread_mutex_lock(&data->mut_print);
	printf("%llu %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data->mut_print);
}
