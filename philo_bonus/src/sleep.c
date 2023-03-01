/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:36:24 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/28 08:24:16 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	sleep_for_eating(t_data *data)
{
	ft_usleep(data->eat_time);
}

int	ft_sleep(t_data *data)
{
	set_philo_state(data, SLEEPING);
	if (print_msg(data, SLEEP))
		return (1);
	ft_usleep(data->sleep_time);
	return (0);
}
