/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:36:39 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/27 11:14:06 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	wait_until(u_int64_t wakeup_time)
{
	const int	margin = 5;
	u_int64_t	time;

	time = get_time();
	while (wakeup_time - time > margin)
	{
		usleep(1000 * (wakeup_time - time - margin));
		time = get_time();
	}
	while (wakeup_time > time)
		time = get_time();
}


void	ft_usleep(uint64_t sleep_time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < sleep_time)
		usleep(500);
}

u_int64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}
