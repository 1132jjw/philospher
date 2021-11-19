/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:43:32 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/26 17:57:50 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo_take_fork(t_philo *philo, int num)
{
	if (philo->is_end || \
	philo->fork[(num + 1) % philo->number_of_philosopher] == 1)
	{
		pthread_mutex_lock(&philo->fork_mutex[num]);
		philo->fork[num] = 0;
		pthread_mutex_unlock(&philo->fork_mutex[num]);
		return (1);
	}
	return (0);
}

void	ft_take_fork(t_philo *philo, int num)
{
	int	phil_num;

	phil_num = philo->number_of_philosopher;
	if (philo_end_check(philo, num))
		return ;
	if (philo->fork[num] == 0 && \
	philo->fork[(num + 1) % phil_num] == 0 \
	&& philo->is_take_fork[num] == 0 && !philo->is_end)
	{
		pthread_mutex_lock(&philo->fork_mutex[num]);
		philo->fork[num] = 1;
		pthread_mutex_unlock(&philo->fork_mutex[num]);
		if (one_philo_take_fork(philo, num))
			return ;
		pthread_mutex_lock(&philo->fork_mutex[(num + 1) % phil_num]);
		philo->fork[(num + 1) % phil_num] = 1;
		pthread_mutex_unlock(&philo->fork_mutex[(num + 1) % phil_num]);
		time_stamp(philo, num, "fork");
		time_stamp(philo, num, "fork");
		philo->is_take_fork[num] = 1;
	}
}

void	ft_put_fork(t_philo *philo, int num)
{
	int	phil_num;

	phil_num = philo->number_of_philosopher;
	if (philo_end_check(philo, num))
		return ;
	if (philo->is_take_fork[num] == 1 && !philo->is_end)
	{
		pthread_mutex_lock(&philo->fork_mutex[num]);
		philo->fork[num] = 0;
		pthread_mutex_unlock(&philo->fork_mutex[num]);
		pthread_mutex_lock(&philo->fork_mutex[(num + 1) % phil_num]);
		philo->fork[(num + 1) % philo->number_of_philosopher] = 0;
		pthread_mutex_unlock(&philo->fork_mutex[(num + 1) % phil_num]);
		philo->is_take_fork[num] = 0;
	}
}
