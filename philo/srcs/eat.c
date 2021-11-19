/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:43:00 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/26 16:48:59 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	while_eat_die(t_philo *philo, int num)
{
	float	after_eat_time;

	gettimeofday(&philo->die_end[num], NULL);
	after_eat_time = time_diff(&philo->die_start[num], &philo->die_end[num]);
	if (philo->time_to_die <= after_eat_time * 1000 + philo->time_to_eat)
	{
		ft_waiting_die(philo, num);
		return (1);
	}
	return (0);
}

void	ft_eat(t_philo *philo, int num)
{
	if (philo_end_check(philo, num))
		return ;
	if (philo->is_eat[num] == 0 && philo->is_take_fork[num] == 1 && \
	!philo->is_end)
	{
		philo->is_eat[num] = 1;
		philo->is_sleep[num] = 0;
		time_stamp(philo, num, "eat");
		if (while_eat_die(philo, num))
			return ;
		ft_usleep_divide(philo->time_to_eat * 1000);
		if (philo->number_of_must_eat != -1)
			philo->num_eat[num]++;
		gettimeofday(&philo->die_start[num], NULL);
	}
}
