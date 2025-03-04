/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:33:25 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/02/24 20:59:35 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# define HAS_FORK 1
# define NOT_HAVE_FORK 0
# define EXIST_FORK 1
# define NOT_EXIST_FORK 0

typedef struct s_ctx	t_ctx;

typedef struct s_philosopher
{
	int					philo_id;
	long long			last_time_ate;
	int					meals_count;
	t_ctx				*ctx;
	pthread_mutex_t		*mutex_right_fork;
	pthread_mutex_t		*mutex_left_fork;
	pthread_t			*individual_thread;
}						t_philosopher;

typedef struct s_ctx
{
	int					num_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					eating_capacity;
	int					full_philos;
	bool				stop;
	t_philosopher		*philos;
	pthread_mutex_t		mutex_printf;
	pthread_mutex_t		mutex_l_t_a;
	pthread_mutex_t		*mutex_forks;
	pthread_mutex_t		mutex_meals_count;
	pthread_mutex_t		mutex_stop;
}						t_ctx;

// init_ctx.c
int						init_ctx(t_ctx **ctx, char **argv, int argc);

// settings.c
int						set_mutex_forks(t_ctx *ctx, int num_philos);
void					set_philo_id(t_philosopher *philos, int num_philos);
void					set_count_meals(t_philosopher *philos, int num_philos);
void					set_philo_eating_status(t_philosopher *philos,
							int num_philos);
void					set_philo_ctx(t_philosopher *philos, t_ctx *ctx);

// initialize_philosophers.c
t_philosopher			*init_philos(int num_philos, t_ctx *ctx);
int						create_insatiable_philos(char **argv, int argc);
void					put_down_forks(t_philosopher *philo);

// create_insatiable_philos.c

// threads.c
void					*start_routine(void *philosopher);
void					lefty_routine(t_philosopher *philo);
void					righty_routine(t_philosopher *philo);
void					lonely_philo_routine(t_philosopher *philo);
// eat.c
void					eat(t_philosopher *philo);
bool					is_ready_to_eat(t_philosopher *philo);
void					put_down_forks(t_philosopher *philo);

// sleep.c
void					get_some_sleep(t_philosopher *philo);

// take_a_fork.c
void					take_a_right_fork(t_philosopher *philo);
void					take_a_left_fork(t_philosopher *philo);

// think.c
void					think(t_philosopher *philo);

// gettimeofday.c
long long				gettimeofday_in_ms(void);

int						create_satiable_philos(char **argv);
// monitor.c
void					*monitor(void *arg);

// print.c
void					print_think(t_philosopher *philo, long long time);
void					print_fork(t_philosopher *philo, long long time);
void					print_eat(t_philosopher *philo, long long time);
void					print_sleep(t_philosopher *philo, long long time);
void					print_die(t_ctx *ctx, int i);

int						ft_atoi(const char *str);

// errors
int						set_mutex_forks_failed(t_ctx *ctx, int fork_nums);
int						ctx_malloc_failed(void);
t_philosopher			*malloc_philos_failed(t_ctx *ctx);
int						threads_create_failed(t_ctx *ctx,
							pthread_t *philo_threads, int i);
// destroy_mutexes.c
int						destroy_mutex_1(t_ctx *ctx, int flag);
int						destroy_mutex_2(t_ctx *ctx);
int						free_mutex_in_ctx(t_ctx *ctx);
void					destroy_mutex_forks(t_ctx *ctx);

// clean.c
int						clean(t_ctx *ctx);
#endif