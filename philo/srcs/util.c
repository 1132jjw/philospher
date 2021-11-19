/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:19:42 by jeujeon           #+#    #+#             */
/*   Updated: 2021/10/17 13:53:13 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;
	size_t			i;

	i = 0;
	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	while (n--)
	{
		if (src1[i] == 0 || src2[i] == 0)
			return ((int)(src1[i] - src2[i]));
		if (src1[i] != src2[i])
			return ((int)(src1[i] - src2[i]));
		i++;
	}
	return (0);
}

void	philo_destroy(t_philo *philo)
{
	pthread_mutex_destroy(&philo->die_mutex);
	pthread_mutex_destroy(&philo->name_mutex);
}

void	philo_free(t_philo *philo)
{
	philo_destroy(philo);
	free(philo->fork_mutex);
	free(philo->die_start);
	free(philo->die_end);
	free(philo->end_time);
	free(philo->thread);
	free(philo->is_take_fork);
	free(philo->num_eat);
	free(philo->is_eat);
	free(philo->is_dead);
	free(philo->is_sleep);
	free(philo->is_think);
	free(philo->fork);
	free(philo);
}

void	philo_join(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philosopher)
	{
		pthread_join(philo->thread[i], NULL);
		i++;
	}
}
