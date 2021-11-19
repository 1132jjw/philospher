/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:28:38 by jeujeon           #+#    #+#             */
/*   Updated: 2021/11/19 15:30:31 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
	{
		free(philo);
		return (1);
	}
	if (arg_check(argc, argv))
	{
		printf("arg_error\n");
		free(philo);
		return (1);
	}
	if (ft_philo_init(philo, argc, argv))
	{
		philo_free(philo);
		return (1);
	}
	philo_create(philo);
	philo_join(philo);
	philo_free(philo);
	return (0);
}
