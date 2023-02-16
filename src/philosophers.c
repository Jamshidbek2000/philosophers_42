/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:19:00 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/16 10:27:06 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	run_threads(t_data *data)
{
	int	i;
	int	nb_of_philos;

	nb_of_philos = get_nb_philos(data);
	i = -1;
	data->start_time = get_time();
	while (++i < nb_of_philos)
	{
		if (pthread_create(&data->philo_ths[i], NULL, &routine, &data->philos[i]))
			return (1);
	}
	if (pthread_create(&data->monit_all_alive, NULL, &all_alive_routine, data))
		return (1);
	if (nb_meals_option(data) == true &&
		pthread_create(&data->monit_all_full, NULL, &all_full_routine, data))
		return (1);

	return (0);
}

int	join_threads(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_nb_philos(data);
	i = -1;
	if (pthread_join(data->monit_all_alive, NULL))
			return (1);
	if (nb_meals_option(data) == true && pthread_join(data->monit_all_full, NULL))
		return (1);
	while (++i < nb_philos)
	{
		if (pthread_join(data->philo_ths[i], NULL))
			return (1);
	}
	return (0);
}

int	philosophers(int argc, char **argv)
{
	t_data	data;

	if (init_data(&data, argc, argv) != 0)
		return (MALLOC_ERROR);
	init_philos(&data);
	init_forks(&data);
	run_threads(&data);
	join_threads(&data);
	
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
		// printf("main check_input\n");
		return (WRONG_INPUT);
	}
	if (philosophers(argc, argv) != 0)
		return (MALLOC_ERROR);

	// printf("\nEND\n");
	return (0);
}

void	print_data(t_data *data)
{
	printf("all alive %d\n", data->keep_iterating);
	// printf("die time %llu\n", data->die_time);
	// printf("sleep time %llu\n", data->sleep_time);
	// printf("eat time %llu\n", data->eat_time);
	// printf("nb meals %d\n", data->nb_meals);
}