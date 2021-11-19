/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:16:48 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/26 17:41:18 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_name(t_philo *philo)
{
	int		name_num;

	pthread_mutex_lock(&philo->name_mutex);
	name_num = philo->num;
	philo->num++;
	pthread_mutex_unlock(&philo->name_mutex);
	return (name_num);
}

void	waiting_create(t_philo *philo)
{
	while (1)
	{
		if (philo->created_philo == philo->number_of_philosopher)
			break ;
	}
}

void	*philo_routine(void *philo_temp)
{
	int		num;
	t_philo	*philo;

	philo = (t_philo *)philo_temp;
	waiting_create(philo);
	num = philo_name(philo);
	gettimeofday(&philo->die_start[num], NULL);
	if (num % 2 == 0)
		ft_usleep_divide(100 * philo->number_of_philosopher);
	while (!philo->is_end)
	{
		ft_take_fork(philo, num);
		ft_eat(philo, num);
		ft_put_fork(philo, num);
		ft_sleep(philo, num);
		ft_think(philo, num);
	}
	return (0);
}
