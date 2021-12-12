/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolsec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:29:12 by symatevo          #+#    #+#             */
/*   Updated: 2021/12/09 21:29:12 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_arg *philo, char *str)
{
	printf("%ld: Philosopher %d %s\n", ft_time() - philo->first_time,
		philo->name, str);
}

void	check_odds(int i, float k)
{
	float	t;

	t = k * 0.9;
	if (!(i % 2))
		ft_usleep(t);
}

t_arg	*ft_init(t_arg *philo, int argc, char **argv, int i)
{
	while (i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(&philo[i].fork, NULL);
		if (i == 0)
			philo[i].prev = NULL;
		else
			philo[i].prev = &philo[i - 1].fork;
		philo[i].philo_num = ft_atoi(argv[1]);
		philo[i].die_time = ft_atoi(argv[2]);
		philo[i].eat_time = ft_atoi(argv[3]);
		philo[i].sleep_time = ft_atoi(argv[4]);
		philo[i].first_time = 0;
		if (argc == 6)
			philo[i].must_eat_time = ft_atoi(argv[5]);
		else
			philo[i].must_eat_time = -1;
		philo[i].last_eat = 0;
		philo[i].total_eat = 0;
		philo[i].name = i + 1;
		i++;
	}
	return (philo);
}
