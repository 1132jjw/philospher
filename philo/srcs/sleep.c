/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:44:13 by jeujeon           #+#    #+#             */
/*   Updated: 2021/10/31 17:31:56 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	while_sleep_die(t_philo *philo, int num)
{
	float	after_eat_time;

	gettimeofday(&philo->die_end[num], NULL);
	after_eat_time = time_diff(&philo->die_start[num], &philo->die_end[num]);
	if (philo->time_to_die <= after_eat_time * 1000 + philo->time_to_sleep)
	{
		ft_waiting_die(philo, num);
		return (1);
	}
	return (0);
}

void	ft_sleep(t_philo *philo, int num)
{
	if (philo_end_check(philo, num))
		return ;
	if (philo->is_eat[num] && philo->is_sleep[num] == 0 && !philo->is_end)
	{
		time_stamp(philo, num, "sleep");
		if (while_sleep_die(philo, num))
			return ;
		ft_usleep_divide(philo->time_to_sleep * 1000);
		philo->is_eat[num] = 0;
		philo->is_sleep[num] = 1;
		usleep(2000);
	}
}
