/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:11:18 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/26 21:49:36 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check(char *str, int i)
{
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	else
		return (0);
}

int	ft_is_blank(char *str, int i)
{
	if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
	str[i] == '\f' || str[i] == '\r' || str[i] == 32)
		return (1);
	else
		return (0);
}

int	ft_is_pm(char *str, int i)
{
	if (str[i] == '+' || str[i] == '-')
		return (1);
	else
		return (0);
}

int	is_over_20digit(int k)
{
	if (k > 0)
		return (-1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		k;
	long	nb;

	nb = 0;
	i = 0;
	k = 1;
	while (ft_is_blank(str, i))
		i++;
	if (ft_is_pm(str, i))
	{
		if (str[i] == '-')
			k = k * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (i > 20)
		return (is_over_20digit(k));
	return (nb * k);
}
