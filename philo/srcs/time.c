/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:32:24 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/26 13:17:43 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	time_stamp(t_philo *philo, int num, char *stat)
{
	float	time;

	gettimeofday(&philo->end_time[num], NULL);
	time = time_diff(&philo->start_time, &philo->end_time[num]);
	if (ft_strncmp(stat, "die", 3) == 0)
		printf("%.0f %d is died\n", time * 1000, num + 1);
	else if (ft_strncmp(stat, "finish", 6) == 0)
		printf("%.0f finish\n", time * 1000);
	if (philo->is_end)
		return ;
	else if (ft_strncmp(stat, "fork", 4) == 0)
		printf("%.0f %d has taken a fork\n", time * 1000, num + 1);
	else if (ft_strncmp(stat, "eat", 3) == 0)
		printf("%.0f %d is eating\n", time * 1000, num + 1);
	else if (ft_strncmp(stat, "sleep", 5) == 0)
		printf("%.0f %d is sleeping\n", time * 1000, num + 1);
	else if (ft_strncmp(stat, "think", 5) == 0)
		printf("%.0f %d is thinking\n", time * 1000, num + 1);
	else if (ft_strncmp(stat, "finish", 6) == 0)
		printf("%.0f finish\n", time * 1000);
}

float	time_diff(struct timeval *start, struct timeval *end)
{
	float	diff;

	diff = (end->tv_sec - start->tv_sec) + \
	1e-6 * (end->tv_usec - start->tv_usec);
	return (diff);
}

int	ft_usleep_divide(int utime)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	while (time_diff(&start, &end) * 1e+6 < utime)
	{
		usleep(100);
		gettimeofday(&end, NULL);
	}
	return (0);
}
