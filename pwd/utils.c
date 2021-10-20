/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:30:30 by akhachat          #+#    #+#             */
/*   Updated: 2021/10/10 19:26:08 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	min;
	long	num;

	i = 0;
	num = 0;
	min = 1;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min = -1;
		i++;
	}
	if (str[i] == '\0')
		ft_error("Error\nWhere are your arguments? :)");
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		num = num * 10;
		num = num + str[i] - '0';
		i++;
		if ((num > 2147483648 && min == -1 ) || (num > 2147483647 && min == 1))
			ft_error("Error\nOutside int range");
	}
	if (str[i] != '\0')
		ft_error("Error\nNon numeric argument");
	if (num == 0 && min == -1)
		ft_error("Error\nWhat? -0? Really?");
	return (num * min);
}

