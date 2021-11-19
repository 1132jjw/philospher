/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:43:56 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/26 16:44:03 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo, int num)
{
	if (philo_end_check(philo, num))
		return ;
	if (philo->is_sleep[num] == 1 && !philo->is_end)
	{
		time_stamp(philo, num, "think");
		philo->is_sleep[num] = 0;
		philo->is_think[num] = 1;
	}
}
