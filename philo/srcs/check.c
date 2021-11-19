/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:34:07 by jeujeon           #+#    #+#             */
/*   Updated: 2021/10/17 13:48:00 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_must_eat_check(t_philo *philo, int num)
{
	int	i;

	pthread_mutex_lock(&philo->die_mutex);
	i = 0;
	while (i < philo->number_of_philosopher)
	{
		if (philo->num_eat[i] < philo->number_of_must_eat && !philo->is_end)
		{
			pthread_mutex_unlock(&philo->die_mutex);
			return (0);
		}
		i++;
	}
	usleep(100);
	if (philo->is_end)
	{
		pthread_mutex_unlock(&philo->die_mutex);
		return (1);
	}
	philo->is_end = 1;
	time_stamp(philo, num, "finish");
	pthread_mutex_unlock(&philo->die_mutex);
	return (1);
}

int	philo_end_check(t_philo *philo, int num)
{
	float	time;

	gettimeofday(&philo->die_end[num], NULL);
	time = time_diff(&philo->die_start[num], &philo->die_end[num]);
	if (time * 1000 >= philo->time_to_die && !philo->is_end)
	{
		pthread_mutex_lock(&philo->die_mutex);
		usleep(100);
		if (philo->is_end != 1)
			time_stamp(philo, num, "die");
		philo->is_end = 1;
		pthread_mutex_unlock(&philo->die_mutex);
		return (1);
	}
	if (philo->is_end)
		return (1);
	if (!philo->is_end && philo->number_of_must_eat != -1)
	{
		if (philo_must_eat_check(philo, num))
			return (1);
		else
			return (0);
	}
	usleep(100);
	return (0);
}

void	ft_waiting_die(t_philo *philo, int num)
{
	float	time;

	gettimeofday(&philo->die_end[num], NULL);
	time = time_diff(&philo->die_start[num], &philo->die_end[num]);
	while (time * 1000 <= philo->time_to_die)
	{
		if (philo->is_end)
			return ;
		usleep(100);
		gettimeofday(&philo->die_end[num], NULL);
		time = time_diff(&philo->die_start[num], &philo->die_end[num]);
	}
	pthread_mutex_lock(&philo->die_mutex);
	usleep(100);
	if (philo->is_end)
	{
		pthread_mutex_unlock(&philo->die_mutex);
		return ;
	}
	philo->is_end = 1;
	time_stamp(philo, num, "die");
	pthread_mutex_unlock(&philo->die_mutex);
}
