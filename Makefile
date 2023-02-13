# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 08:22:06 by jergashe          #+#    #+#              #
#    Updated: 2023/02/12 15:29:11 by jergashe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

SRCS = src/philosophers.c	\
		src/parse.c	\
		src/init_data.c	\
		src/routine.c	\
		src/time.c	\
		src/utils.c	\
		src/monitoring.c	\
		src/eat.c	\
		src/sleep.c	\
		src/think.c	\
		

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME) 

re: fclean all

.PHONY: all clean fclean re