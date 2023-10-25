/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:21:40 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/27 11:14:06 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//philo_died(philo) || 
void	*routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *) philo_p;
	update_last_meal_time(philo);
	while (get_philo_state(philo) != DEAD)
	{
		if (eat(philo) != 0)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (think(philo) != 0)
			break ;
	}
	return (NULL);
}
	// pthread_mutex_lock(&philo->data->mut_print);
	// write(1, "\t\tFINISHED\n",11);
	// printf("\t\tPHILO %d exited\n", philo->id);
	// pthread_mutex_unlock(&philo->data->mut_print);

void	print_nb_meals_had(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->mut_print);
	printf("Philo %d ate %d times\n", philo->id, philo->nb_meals_had);
	pthread_mutex_unlock(&data->mut_print);
}

// void	think_if_id_is_even(t_philo *philo)
// {
// 	if (philo->id % 2 == 0)
// 	{
// 		print_msg(philo->data, philo->id, THINK);
// 		ft_usleep((get_eat_time(philo->data) / 2));
// 	}
// }