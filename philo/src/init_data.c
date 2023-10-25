/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:16:17 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/01 07:56:23 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_forks(t_data *data)
{
	int		i;
	t_philo	*philos;

	philos = data->philos;
	i = -1;
	while (++i < data->nb_philos)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	philos[0].left_f = &data->forks[0];
	philos[0].right_f = &data->forks[data->nb_philos - 1];
	while (++i < data->nb_philos)
	{
		philos[i].left_f = &data->forks[i];
		philos[i].right_f = &data->forks[i - 1];
	}
	return (0);
}

int	init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = -1;
	philos = data->philos;
	while (++i < data->nb_philos)
	{
		philos[i].data = data;
		philos[i].id = i + 1;
		philos[i].nb_meals_had = 0;
		philos[i].state = IDLE;
		pthread_mutex_init(&philos[i].mut_state, NULL);
		pthread_mutex_init(&philos[i].mut_nb_meals_had, NULL);
		pthread_mutex_init(&philos[i].mut_last_eat_time, NULL);
		update_last_meal_time(&philos[i]);
	}
	return (0);
}

int	malloc_data(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (data->philos == NULL)
		return (MALLOC_ERROR);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (data->forks == NULL)
		return (free(data->philos), MALLOC_ERROR);
	data->philo_ths = malloc(sizeof(pthread_t) * data->nb_philos);
	if (data->philo_ths == NULL)
		return (free(data->philos), free(data->forks), MALLOC_ERROR);
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->nb_full_p = 0;
	data->keep_iterating = true;
	data->nb_philos = ft_atoi(argv[1]);
	data->die_time = (u_int64_t) ft_atoi(argv[2]);
	data->eat_time = (u_int64_t) ft_atoi(argv[3]);
	data->sleep_time = (u_int64_t) ft_atoi(argv[4]);
	data->nb_meals = -1;
	if (argc == 6)
		data->nb_meals = ft_atoi(argv[5]);
	pthread_mutex_init(&data->mut_eat_t, NULL);
	pthread_mutex_init(&data->mut_sleep_t, NULL);
	pthread_mutex_init(&data->mut_die_t, NULL);
	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_nb_philos, NULL);
	pthread_mutex_init(&data->mut_keep_iter, NULL);
	pthread_mutex_init(&data->mut_start_time, NULL);
	return (malloc_data(data));
}
