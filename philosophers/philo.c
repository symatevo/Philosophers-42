#include "philo.h"

void    *print(void *str)
{
    write(1, "hi", 2);
    for(int i = 0; i < 20; i++)
        write(1, (char *)str, strlen(str));
}

int     create_philosophers(int philos, int die, int eat, int sleep, int each_eat_time)
{
    int number;
    number = 0;
    char *str = "1_1_1_1_1_1_1_1_1_1_1\n"
    while (number != philos)
    {
        pthread_t new_philo[number];
        phtread_create(new_philo[number], NULL, print, (void*)str)
    }
    usleep(300000);
}

int     philo(int number_of_philosophers, int time_to_die, int time_to_eat, int time_to_sleep, int number_of_times_each_philoshoper_must_eat)
{
    if(!(create_philosophers(number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, number_of_times_each_philoshoper_must_eat))
        exit(0);
}

int     main()
{
    philo(3)
}