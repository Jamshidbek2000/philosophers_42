/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:21:43 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/28 10:56:05 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	drop_forks(t_data *data)
{
	sem_post(data->sem_forks);
	sem_post(data->sem_forks);
	return (0);
}

bool	nb_meals_option_given(t_data *data)
{
	if (data->nb_meals > 0)
		return (true);
	return (false);
}

bool	philo_is_full(t_data *data)
{
	if (nb_meals_option_given(data) == false)
		return (false);
	if (data->nb_meals <= data->philo.nb_meals_had)
	{
		set_philo_state(data, FULL);
		return (true);
	}
	return (false);
}

int	take_forks(t_data *data)
{
	sem_wait(data->sem_forks);
	if (print_msg(data, TAKE_FORKS))
	{
		sem_post(data->sem_forks);
		return (1);
	}
	if (data->nb_philos == 1)
		return (1);
	sem_wait(data->sem_forks);
	if (should_stop(get_philo_state(data)))
	{
		drop_forks(data);
		return (1);
	}
	if (print_msg(data, TAKE_FORKS))
	{
		drop_forks(data);
		return (1);
	}
	return (0);
}

int	eat(t_data *data)
{
	if (take_forks(data))
		return (1);
	update_last_meal_time(data);
	set_philo_state(data, EATING);
	if (print_msg(data, EAT))
	{
		drop_forks(data);
		return (1);
	}
	sleep_for_eating(data);
	drop_forks(data);
	data->philo.nb_meals_had++;
	if (philo_is_full(data))
		return (1);
	return (0);
}
