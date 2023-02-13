/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:51:45 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/13 09:07:15 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_f);
	print_msg(philo->data, philo->id, TAKE_FORKS);
	pthread_mutex_lock(philo->left_f);
	print_msg(philo->data, philo->id, TAKE_FORKS);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
}

void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_l_m_t);
	philo->last_eat_time = get_time(); 
	pthread_mutex_unlock(&philo->mut_l_m_t);
}

void	update_nb_meals_had(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	philo->nb_meals_had++;
	if (philo->nb_meals_had == philo->nb_meals)
	{
		pthread_mutex_lock(&data->mut_nb_full_p);
		data->nb_full_p++;
		pthread_mutex_unlock(&data->mut_nb_full_p);
	}
}

int	eat(t_philo *philo)
{
	take_forks(philo);
	change_philo_state(philo, EATING);
	usleep(philo->eat_time * 1000);
	update_last_meal_time(philo);
	update_nb_meals_had(philo);
	drop_forks(philo);
	return (0);
}