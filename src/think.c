/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:00:14 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/13 09:10:12 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	think(t_philo *philo)
{
	change_philo_state(philo, THINKING);
	print_msg(philo->data, philo->id, THINK);
	return (0);
}
