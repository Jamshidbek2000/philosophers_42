/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:35:25 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/28 08:29:36 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

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

// MAYBE <=
int	negative_input_check(int argc, char **argv)
{
	int	index;

	index = 1;
	while (index < argc)
	{
		if (ft_atoi(argv[index]) <= 0)
			return (WRONG_INPUT);
		index++;
	}
	return (0);
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
	{
		return (WRONG_INPUT);
	}
	if (argc > 6)
	{
		return (WRONG_INPUT);
	}
	if (is_input_digit(argc, argv) != 0)
	{
		return (WRONG_INPUT);
	}
	if (wrong_input_check(argc, argv) != 0)
		return (WRONG_INPUT);
	return (0);
}
