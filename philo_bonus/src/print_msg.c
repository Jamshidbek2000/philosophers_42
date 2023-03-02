/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:00:16 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/02 11:38:10 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

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

void	print_instruction(void)
{
	printf("\t\t\t\t\t\tWRONG INPUT!\n\n");
	printf("./philo_bonus nb_philos time_to_die ");
	printf("time_to_eat time_to_sleep ");
	printf("number_of_times_each_philosopher_must_eat ");
	printf("(optional argument)\n");
	printf("Example:\n\n");
	printf("./philo_bonus 4 800 200 200 5\n\n");
	printf("nb_philos: 1-200\n");
	printf("time_to_die: 60+\n");
	printf("time_to_eat: 60+\n");
	printf("time_to_sleep: 60+\n");
	printf("number_of_times_each_philosopher_must_eat: ");
	printf("0+\n");
}

void	print_sem(t_data *data, char *str)
{
	sem_wait(data->sem_print);
	printf("%s\n", str);
	sem_post(data->sem_print);
}
