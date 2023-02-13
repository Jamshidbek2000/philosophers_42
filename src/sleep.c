/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:28:28 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/13 09:10:00 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_sleep(t_philo *philo)
{
	change_philo_state(philo, SLEEPING);
	print_msg(philo->data, philo->id, SLEEP);
	usleep(philo->sleep_time * 1000);
	
	return (0);
}
