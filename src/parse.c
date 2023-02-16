/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:14:32 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/16 10:27:26 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	wrong_input_check(int argc, t_data *data)
{
	if (argc == 6 && data->nb_meals < 0)
		return (WRONG_INPUT);
	// if (data->die_time < 0 || data->eat_time < 0
	// 	|| data->sleep_time < 0 || data->nb_philos <= 0)
	// 	return (WRONG_INPUT);
	return (0);
}

int	negative_input_check(int argc, char **argv) // MAY NOT NEED
{
	int	index;

	index = 1;
	while (index < argc)
	{
		if (ft_atoi(argv[index]) < 0) // MAYBE <=
			return (WRONG_INPUT);
		index++;
	}
	return (0);
}

int	ft_atoi(const char *str)
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
				printf("is_input_digit: i=%d k=%d\n", i, k);
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
	{
		printf("check_input argc<5\n");
		return (WRONG_INPUT);
	}
	if (argc > 6)
	{
		printf("check_input argc>6\n");
		return (WRONG_INPUT);
	}
	if (is_input_digit(argc, argv) != 0)
	{
		printf("check_input is_input_digit\n");
		return (WRONG_INPUT);
	}
	return (0);
}
