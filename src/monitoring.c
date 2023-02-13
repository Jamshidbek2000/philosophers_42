/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:47:58 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/11 14:55:20 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*full_philos(void *data_p) // Do I need it?
{// philosophers will be checking it themselves 
	t_data	*data;

	data = (t_data *) data_p;
	while (1)
	{
		pthread_mutex_lock(&data->mut_nb_full_p);
		if (data->nb_full_p == data->nb_philos)
			break ;
		pthread_mutex_unlock(&data->mut_nb_full_p);
	}
	return ((void *)0);
}

bool	all_alive(t_data *data)
{
	bool	result;

	result = true;
	pthread_mutex_lock(&data->mut_all_alive);
	if (data->all_alive == false)
		result = false;
	pthread_mutex_lock(&data->mut_all_alive);
	return (result);
}
