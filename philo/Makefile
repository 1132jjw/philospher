# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 17:01:21 by jeujeon           #+#    #+#              #
#    Updated: 2021/10/17 14:16:07 by jeujeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	philo
SRCS		=	srcs/main.c\
				srcs/eat.c\
				srcs/sleep.c\
				srcs/think.c\
				srcs/fork.c\
				srcs/arg.c\
				srcs/init.c\
				srcs/time.c\
				srcs/util.c\
				srcs/check.c\
				srcs/philo_function.c\
				srcs/philo_routine.c\
				srcs/ft_atoi.c

OBJS	=		$(SRCS:.c=.o)

.c.o		:	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all			:	$(NAME)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all

.PHONY		:	all, clean, fclean, re, pipex
