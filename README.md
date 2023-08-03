# Philosophers

The goal is to create a simulation of a dining table with multiple philosophers, each representing a thread, and forks that the philosophers share to eat their meals.

## Summary

In this project, you are required to simulate the dining philosophers problem with a fixed number of philosophers sitting around a table. Each philosopher needs two forks to eat a meal, and the forks are placed between adjacent philosophers. The challenge is to ensure that the philosophers can eat their meals without deadlocking (holding onto resources indefinitely) and without starving (waiting indefinitely for a fork).

## Skills to Learn

- Multithreading
- Synchronization
- Deadlock Prevention
- Starvation Avoidance
- Problem Solving

## The "Philosophers" Program

### Usage

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

### Description

The "philosophers" program creates a simulation of the dining philosophers problem with the specified number of philosophers sitting around a table. It takes various arguments as input to configure the simulation:

- `number_of_philosophers`: The number of philosophers at the table.
- `time_to_die`: The time (in milliseconds) after which a philosopher dies if they have not eaten.
- `time_to_eat`: The time (in milliseconds) it takes for a philosopher to finish eating.
- `time_to_sleep`: The time (in milliseconds) a philosopher spends sleeping between meals.
- `number_of_times_each_philosopher_must_eat`: The optional argument that specifies the number of times each philosopher must eat before the simulation stops. If not provided, the simulation runs indefinitely.

## Project Constraints

- Each philosopher is a thread, and forks are shared resources between them.
- Philosophers can only eat if they have both left and right forks.
- Philosophers should not be able to die of starvation or deadlock.
- The simulation should end when a philosopher dies or when all philosophers have eaten the required number of times.

## Example Usage

```bash
$> ./philo 5 800 200 200 7
```
