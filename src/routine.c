/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:21:40 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/16 08:41:14 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	think_if_id_is_even(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		print_msg(philo->data, philo->id, THINK);
		ft_usleep((get_eat_time(philo->data) / 2));
	}
}

bool	philo_died(t_philo *philo) // philo checks himself
{
	bool		result;
	t_data		*data;

	data = philo->data;
	result = false;
	if (get_time() - philo->last_eat_time > get_die_time(data))
	{		
		set_philo_state(philo, DEAD);
		print_msg(data, philo->id, DIED);
		result = true;
	}
	return (result);
}

void	*routine(void *philo_p)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *) philo_p;
	data = philo->data;

	update_last_meal_time(philo);
	// think_if_id_is_even(philo);
	while (true)
	{
		if (philo_died(philo) || get_philo_state(philo) == DEAD)
			break ;
		if (eat(philo) != 0)
			break ;
		if (philo_died(philo) || get_philo_state(philo) == DEAD)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (philo_died(philo) || get_philo_state(philo) == DEAD)
			break ;
		if (think(philo) != 0)
			break ;
	}

	pthread_mutex_lock(&philo->data->mut_print);
	// write(1, "\t\tFINISHED\n",11);
	printf("\t\tPHILO %d exited\n", philo->id);
	pthread_mutex_unlock(&philo->data->mut_print);
	
	return (NULL);
}


void	print_nb_meals_had(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->mut_print);
	printf("Philo %d ate %d times\n", philo->id, philo->nb_meals_had);
	pthread_mutex_unlock(&data->mut_print);
}