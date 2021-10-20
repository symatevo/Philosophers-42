/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:28:56 by akhachat          #+#    #+#             */
/*   Updated: 2021/10/20 19:32:24 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        ++i;
    return (i);
}

void ft_error(char *str)
{
    write(2, str, ft_strlen(str));
    exit(0);
}

void    ft_init(int argc, char **argv)
{
    arg.philo_num = ft_atoi(argv[1]);
    arg.die_time = ft_atoi(argv[2]);
    arg.eat_time = ft_atoi(argv[3]);
    arg.sleep_time = ft_atoi(argv[4]);
    arg.forks = (pthread_mutex_t *)malloc((arg.philo_num) * sizeof(pthread_mutex_t)); 
    if (argc == 6)
        arg.must_eat_time = atoi(argv[5]);
}


void  parsing(int argc, char **argv)
{

    if ((argc != 5 && argc != 6) || *argv[1] == '0')
        ft_error("Error: argument\n");
    else if(*argv[1] == '1')
        ft_error("is dead\n");
    ft_init(argc, argv);
    
    //mutexneri zangvacy chenq stugel qcuma te che
   /* printf("num%d\n", arg.philo_num);
    printf("die%d\n", arg.die_time);
    printf("eat%d\n", arg.eat_time);
    printf("sleep%d\n", arg.sleep_time);
    printf("must%d\n", arg.must_eat_time);*/
}

void pickup(int i)
{
	pthread_mutex_lock(&mutex[i]);
	state[i] = HUNGRY;
	test(i);
	pthread_mutex_unlock(&mutex[i]);
}

void think(int i)
{
	printf("Philosopher %d is thinking", i);
}

void eat(int i)
{
	printf("Philosopher %d is eating", i);
	usleep(arg.eat_time);
}
	
void test(int i)
{
	int left = LEFT;
	if (left == 0) 
		left += arg.philo_num
	if (state[i] == HUNGRY && state[left] != EATING && state[right] != EATING)
	{
		pthread_mutex_lock(&mutex[i+1]);
		state[i] = EATING;
		eat();
		pthread_mutex_unlock(&mutex[i+1]);
	}
}

void sleeping(int i)
{
	printf("Philosopher %d is sleeping", i);
	usleep(arg.sleep_time);
}

void philosopher(void data)
{
	int i = data;
	while (!quit)
	{
		think(i);
		pickup(i);
		sleeping(i);
	}
}

void thread_creates()
{
    pthread_t ph[arg.philo_num];
    int i;
    

    i = 0;
	while (i <= arg.philo_num)
	{
		pthread_mutex_init(arg.forks[i], NULL);
		i++;
	}
    while (i <= arg.philo_num)
    {
        pthread_create(ph + i, NULL, &life, NULL);
        i++;
    }

}

int main(int argc, char **argv)
{
    parsing(argc, argv);
    thread_creates();
    return (0);
}
