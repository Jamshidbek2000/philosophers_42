/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:16:17 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/12 10:43:08 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

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
	int	i;

	i = -1;
	philos = data->philos;
	while (++i < data->nb_philos)
	{
		// printf("init philo %d\n", i+1);
		philos[i].data = data;
		philos[i].die_time = data->die_time;
		philos[i].sleep_time = data->sleep_time;
		philos[i].eat_time = data->eat_time;
		philos[i].id = i + 1;
		philos[i].nb_meals = data->nb_meals;
		philos[i].nb_meals_had = 0;
		philos[i].state = IDLE;
		pthread_mutex_init(&philos[i].mut_l_m_t, NULL);
		pthread_mutex_init(&philos[i].mut_state, NULL);
	}
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->nb_full_p = 0;
	data->all_alive = true;
	data->nb_philos = ft_atoi(argv[1]);
	data->die_time = (u_int64_t) ft_atoi(argv[2]);
	data->eat_time = (u_int64_t) ft_atoi(argv[3]);
	data->sleep_time = (u_int64_t) ft_atoi(argv[4]);
	data->nb_meals = -1;
	if (argc == 6)
		data->nb_meals = ft_atoi(argv[5]);
	if (wrong_input_check(argc, data) == WRONG_INPUT) // MAYBE DONT NEED
		return (WRONG_INPUT);
	
	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_all_alive, NULL);
	pthread_mutex_init(&data->mut_nb_meals, NULL);
	pthread_mutex_init(&data->mut_nb_full_p, NULL);

	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (data->philos == NULL)
		return (MALLOC_ERROR);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (data->forks == NULL)
		return (free(data->philos), MALLOC_ERROR);
	
	return (0);
}
