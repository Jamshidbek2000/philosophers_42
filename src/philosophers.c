/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:19:00 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/12 15:28:40 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	run_threads(t_data *data)
{
	int			i;
	pthread_t	monit;

	data->start_time = get_time();
	if (data->nb_meals > 0
		&& pthread_create(&monit, NULL, &all_alive_check, data))
		return (1);
	
	i = -1;
	while (++i < data->nb_philos)
	{
		if (pthread_create(&data->philos[i].th, NULL, &routine, &data->philos[i]))
			return (1);
	}
	i = -1;
	while (++i < data->nb_philos)
	{
		if (pthread_join(data->philos[i].th, NULL))
			return (1);
	}
	return (0);
}

int	philosophers(int argc, char **argv)
{
	t_data	data;

	init_data(&data, argc, argv);
	init_philos(&data);
	init_forks(&data);
	
	free_data(&data);
	
	return (0);
}

void	leaks()
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	// atexit(&leaks);
	if (check_input(argc, argv) != 0)
	{
		printf("main check_input\n");
		return (WRONG_INPUT);
	}
	philosophers(argc, argv);

	printf("\nEND\n");

	return (0);
}

	// uint64_t	time;

	// time = get_time();
	// printf("TIME: %llu\n", time);