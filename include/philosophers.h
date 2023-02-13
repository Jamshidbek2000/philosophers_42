/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:21:01 by jergashe          #+#    #+#             */
/*   Updated: 2023/02/13 09:08:36 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

# include <stdbool.h>

# define WRONG_INPUT 1
# define MALLOC_ERROR 2

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}	t_state;

struct	s_data;

typedef struct s_philo
{
	int				id;
	t_state			state;
	struct s_data	*data;
	int				nb_meals;
	int				nb_meals_had;
	pthread_t		th;

	u_int64_t		eat_time;
	u_int64_t		die_time;
	u_int64_t		sleep_time;
	
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	mut_state;
	pthread_mutex_t	mut_l_m_t;
	
	u_int64_t		start_time; // not sure
	u_int64_t		last_eat_time;

	
}t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				nb_meals;
	int				nb_full_p;
	bool			all_alive;
	
	u_int64_t		eat_time;
	u_int64_t		die_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;

	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_nb_full_p;
	pthread_mutex_t	mut_all_alive;
	pthread_mutex_t	mut_nb_meals;
	
	pthread_mutex_t	*forks;
	t_philo			*philos;
}t_data;



// routine.c
void	*all_alive_check(void *data_p);
void	*routine(void *philo_p);
bool	all_alive_and_full_check(t_data *data);

// parse.c
int		check_input(int argc, char **argv);
int		wrong_input_check(int argc, t_data *data);
int		negative_input_check(int argc, char **argv);
int		ft_atoi(const char *str);

// init_data.c
int		init_data(t_data *data, int argc, char **argv);
int		init_philos(t_data *data);
int		init_forks(t_data *data);

// time.c
u_int64_t	get_time(void);

// monitoring.c
bool	all_alive(t_data *data);
void	*full_philos(void *data_p); // Do I need it?

// eat.c
int		eat(t_philo *philo);

// sleep.c
int		ft_sleep(t_philo *philo);

// think.c
int		think(t_philo *philo);

// utils.c
void	free_data(t_data *data);
bool	all_alive(t_data *data);
bool	all_full(t_data *data);
void	print_msg(t_data *data, int id, char *msg);
void	change_philo_state(t_philo *philo, t_state state);

#endif