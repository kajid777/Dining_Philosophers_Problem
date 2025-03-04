/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:07:11 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/02/24 20:45:52 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	count_increment(t_philosopher *philo)
{
	pthread_mutex_lock(&(philo->ctx->mutex_meals_count));
	philo->meals_count++;
	pthread_mutex_unlock(&(philo->ctx->mutex_meals_count));
}

void	eat(t_philosopher *philo)
{
	int			i;
	long long	time;

	i = 0;
	time = gettimeofday_in_ms();
	print_eat(philo, time);
	while (i < (philo->ctx->time_to_eat))
	{
		usleep(909);
		i++;
	}
	pthread_mutex_lock(&(philo->ctx->mutex_l_t_a));
	philo->last_time_ate = gettimeofday_in_ms();
	pthread_mutex_unlock(&(philo->ctx->mutex_l_t_a));
	put_down_forks(philo);
	count_increment(philo);
}

void	put_down_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(philo->mutex_right_fork);
	pthread_mutex_unlock(philo->mutex_left_fork);
}
