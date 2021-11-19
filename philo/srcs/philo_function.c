/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:02:35 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/26 17:39:17 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->name_mutex);
	philo->created_philo++;
	pthread_mutex_unlock(&philo->name_mutex);
}

void	philo_create(t_philo *philo)
{
	int		i;
	int		is_error;

	i = 0;
	while (i < philo->number_of_philosopher)
	{
		is_error = \
		pthread_create(&philo->thread[i], NULL, philo_routine, philo);
		if (is_error != 0)
			return ;
		if (philo->created_philo == philo->number_of_philosopher - 1)
			gettimeofday(&philo->start_time, NULL);
		philo_count(philo);
		usleep(200);
		i++;
	}
}
