/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:36:24 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/27 11:15:29 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	sleep_for_eating(t_data *data)
{
	wait_until(data->eat_time + get_time());
}

int	ft_sleep(t_data *data)
{
	set_philo_state(data, SLEEPING);
	if (print_msg(data, SLEEP))
		return (1);
	wait_until(data->sleep_time + get_time());
	return (0);
}
