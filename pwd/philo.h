/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:28:29 by akhachat          #+#    #+#             */
/*   Updated: 2021/10/20 18:52:49 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define HUNGRY 0
#define EATING 1
#define THINKING 2

struct arg
{
    int philo_num;
    int die_time;
    int eat_time;
    int sleep_time;
    int must_eat_time;
    pthread_mutex_t *forks;
} arg;

#define LEFT (i - 1) % arg.philo_num
#define RIGHT (i + 1) % arg.philo_num

typedef struct s_philo
{
    int name;
}       philo;

void    parsing(int argc, char **argv);
int     ft_strlen(char *str);
void    ft_error(char *str);
int     ft_atoi(char *str);
void    thread_creates();


#endif
