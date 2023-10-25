/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:14:32 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/02 09:42:08 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_instruction(void)
{
	printf("\t\tWRONG INPUT!\n\n");
	printf("./philo nb_philos time_to_die ");
	printf("time_to_eat time_to_sleep ");
	printf("number_of_times_each_philosopher_must_eat ");
	printf("(optional argument)\n");
	printf("Example:\n\n");
	printf("./philo 4 800 200 200 5\n\n");
	printf("nb_philos: 1-200\n");
	printf("time_to_die: 60+\n");
	printf("time_to_eat: 60+\n");
	printf("time_to_sleep: 60+\n");
	printf("number_of_times_each_philosopher_must_eat: ");
	printf("0+\n");
}

int	wrong_input_check(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
		return (WRONG_INPUT);
	if (ft_atoi(argv[i]) < 1 || ft_atoi(argv[i]) > 200)
		return (WRONG_INPUT);
	while (++i < 5)
	{
		if (ft_atoi(argv[i]) < 60)
			return (WRONG_INPUT);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int		count;
	long	result;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while (str[count] == '\r' || str[count] == '\t' || str[count] == ' '
		|| str[count] == '\f' || str[count] == '\v' || str[count] == '\n')
		count++;
	if (str[count] == '-')
	{
		sign = -1;
		count++;
	}
	else if (str[count] == '+')
		count++;
	if (!(str[count] >= '0' && str[count] <= '9'))
		return (0);
	while (str[count] >= '0' && str[count] <= '9')
		result = result * 10 + (str[count++] - '0');
	return (result * sign);
}

int	is_input_digit(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (i < argc)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			if (argv[i][k] < '0' || argv[i][k] > '9')
			{
				return (WRONG_INPUT);
			}
			k++;
		}
		i++;
	}
	return (0);
}

int	check_input(int argc, char **argv)
{
	if (argc < 5)
		return (WRONG_INPUT);
	if (argc > 6)
		return (WRONG_INPUT);
	if (is_input_digit(argc, argv) != 0)
		return (WRONG_INPUT);
	if (wrong_input_check(argc, argv))
		return (WRONG_INPUT);
	return (0);
}
