/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:28:59 by symatevo          #+#    #+#             */
/*   Updated: 2021/12/09 21:28:59 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_arg
{
	pthread_mutex_t	fork;
	pthread_mutex_t	*state;
	pthread_mutex_t	*eats;
	pthread_mutex_t	*prev;
	int				philo_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	long			first_time;
	long			last_eat;
	int				total_eat;
	int				name;
	int				must_eat_time;
}					t_arg;

int		parsing(int argc, char **argv);
void	print(t_arg *philo, char *str);
t_arg	*ft_init(t_arg *philo, int argc, char **argv, int i);
long	ft_time(void);
void	ft_usleep(int time);
int		ft_atoi(char *str);
void	check_odds(int i, float k);

#endif
