/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:00:16 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/27 11:15:29 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (s1[count] != '\0' && s2[count] != '\0' && count < n)
	{
		if (s1[count] != s2[count])
		{
			return ((unsigned char) s1[count] - (unsigned char) s2[count]);
		}
		count++;
	}
	if (count < n)
		return ((unsigned char) s1[count] - (unsigned char) s2[count]);
	return (0);
}

int	print_msg(t_data *data, char *msg)
{
	sem_wait(data->sem_print);
	if (someone_died())
	{
		sem_post(data->sem_print);
		return (1);
	}
	printf("%llu %d %s\n", get_time() - get_start_time(data),
		data->philo.id, msg);
	sem_post(data->sem_print);
	return (0);
}

void	print_sem(t_data *data, char *msg)
{
	sem_wait(data->sem_print);
	printf("%s\n", msg);
	sem_post(data->sem_print);
}
