/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:51:45 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/16 08:50:42 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (philo_died(philo) || get_philo_state(philo) == DEAD)
			return (1);
		pthread_mutex_lock(philo->right_f);
		print_msg(philo->data, philo->id, TAKE_FORKS);
		if (philo_died(philo) || get_philo_state(philo) == DEAD)
		{
			pthread_mutex_unlock(philo->right_f);
			return (1);
		}
		pthread_mutex_lock(philo->left_f);
		print_msg(philo->data, philo->id, TAKE_FORKS);
	}
	else
	{
		if (philo_died(philo) || get_philo_state(philo) == DEAD)
			return (1);
		pthread_mutex_lock(philo->left_f);
		print_msg(philo->data, philo->id, TAKE_FORKS);
		if (philo_died(philo) || get_philo_state(philo) == DEAD)
		{
			pthread_mutex_unlock(philo->left_f);
			return (1);
		}
		pthread_mutex_lock(philo->right_f);
		print_msg(philo->data, philo->id, TAKE_FORKS);
	}
	return (0);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
}

void	update_last_meal_time(t_philo *philo)
{
	philo->last_eat_time = get_time();
}

void	update_nb_meals_had(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_nb_meals_had);
	philo->nb_meals_had++;
	pthread_mutex_unlock(&philo->mut_nb_meals_had);
}

void	sleep_for_eating(t_philo *philo)
{
	ft_usleep(get_eat_time(philo->data));
}

int	eat(t_philo *philo)
{
	if (take_forks(philo) != 0)
		return (1);
	set_philo_state(philo, EATING);
	print_msg(philo->data, philo->id, EAT);
	sleep_for_eating(philo);
	if (philo_died(philo) || get_philo_state(philo) == DEAD)
	{
		drop_forks(philo);
		return (1);
	}
	update_last_meal_time(philo);
	update_nb_meals_had(philo);
	drop_forks(philo);
	return (0);
}

void	print_nb_full_p(t_data *data)
{
	pthread_mutex_lock(&data->mut_print);
	printf("%d FULL(%d) PHILOS\n", data->nb_full_p, data->nb_meals);
	pthread_mutex_unlock(&data->mut_print);
}