/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:16:18 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/28 10:33:51 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	run_processes(t_data *data)
{
	pid_t	p_id;
	int		i;

	i = 0;
	data->start_time = get_time();
	while (i++ < data->nb_philos)
	{
		p_id = fork();
		if (p_id == 0)
		{
			start_routine(data, i);
		}
		else if (p_id == -1)
			return (FORK_ERROR);
	}
	p_id = waitpid(0, NULL, 0);
	while (p_id != -1)
		p_id = waitpid(0, NULL, 0);
	return (0);
}

void	clean_up(t_data *data)
{
	sem_close(data->sem_forks);
	sem_close(data->sem_print);
}

int	philosophers_bonus(int argc, char **argv)
{
	t_data	data;

	if (init_data(&data, argc, argv) != 0)
		return (WRONG_INPUT);
	run_processes(&data);
	clean_up(&data);
	return (0);
}

void	leaks(void)
{
	system("leaks philo");
}

	// atexit(leaks);
int	main(int argc, char **argv)
{
	if (check_input(argc, argv) != 0)
	{
		print_instruction();
		return (WRONG_INPUT);
	}
	philosophers_bonus(argc, argv);
	return (0);
}
