/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:28:29 by symatevo          #+#    #+#             */
/*   Updated: 2021/12/09 21:28:29 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*eat_loop(void *ptr)
{
	t_arg	*philo;
	int		i;

	philo = (t_arg *)ptr;
	i = 0;
	if (philo->must_eat_time != 0)
		pthread_mutex_lock(philo->eats);
	while (philo->must_eat_time != 0 && i < philo->philo_num)
	{
		pthread_mutex_lock(philo->eats);
		i++;
	}
	printf("Everyone has eaten enough\n");
	pthread_mutex_unlock(philo->state);
	return (NULL);
}

void	*check_death(void *ptr)
{
	t_arg	*philo;

	philo = (t_arg *)ptr;
	while (1)
	{
		if (ft_time() - philo->last_eat > philo->die_time)
		{
			printf("%lu: Philosopher %d is died\n",
				ft_time() - philo->first_time, philo->name);
			pthread_mutex_unlock(philo->state);
			return (NULL);
		}
		else if (philo->must_eat_time != -1 && \
			philo->total_eat >= philo->must_eat_time)
		{
			ft_usleep(philo->name);
			pthread_mutex_unlock(philo->eats);
			return (NULL);
		}
	}
	return (NULL);
}

void	*life(void *ptr)
{
	pthread_t	tid;
	t_arg		*p;

	p = (t_arg *)ptr;
	pthread_create(&tid, NULL, check_death, p);
	check_odds(p->name, p->eat_time);
	while (p->must_eat_time == -1 || p->must_eat_time > p->total_eat)
	{
		pthread_mutex_lock(&p->fork);
		print(p, "has taken a fork");
		pthread_mutex_lock(p->prev);
		print(p, "has taken a fork");
		p->last_eat = ft_time();
		print(p, "is eating");
		ft_usleep(p->eat_time);
		pthread_mutex_unlock(&p->fork);
		pthread_mutex_unlock(p->prev);
		p->total_eat++;
		print(p, "is sleeping");
		ft_usleep(p->sleep_time);
		print(p, "is thinking");
	}
	return (NULL);
}

void	ft_philo(t_arg *philo)
{
	pthread_mutex_t	state;
	pthread_mutex_t	eats;
	pthread_t		tid;
	int				i;

	philo[0].prev = &philo[philo[0].philo_num - 1].fork;
	pthread_mutex_init(&state, NULL);
	pthread_mutex_init(&eats, NULL);
	pthread_mutex_lock(&state);
	i = 0;
	while (i < philo[0].philo_num)
	{
		philo[i].state = &state;
		philo[i].eats = &eats;
		pthread_create(&tid, NULL, life, &philo[i++]);
	}
	if (philo[0].must_eat_time > -1)
		pthread_create(&tid, NULL, eat_loop, &philo[0]);
	pthread_mutex_lock(&state);
	pthread_mutex_destroy(&state);
	pthread_mutex_destroy(&eats);
	free(philo);
}

int	main(int argc, char **argv)
{
	t_arg	*philo;
	int		i;

	if (parsing(argc, argv) == 0 || ft_atoi(argv[1]) == 0)
		return (1);
	philo = malloc(sizeof(t_arg) * ft_atoi(argv[1]));
	if (!(philo))
		return (1);
	i = 0;
	philo = ft_init(philo, argc, argv, i);
	while (i < ft_atoi(argv[1]))
	{
		philo[i].first_time = ft_time();
		philo[i].last_eat = philo[i].first_time;
		i++;
	}
	ft_philo(philo);
	i = 0;
	while (i < philo[0].philo_num)
		pthread_mutex_destroy(&philo[i++].fork);
	return (0);
}
