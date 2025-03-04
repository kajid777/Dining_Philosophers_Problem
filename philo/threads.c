/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:34:17 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/03/02 11:33:59 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*start_routine(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	if (philo->ctx->num_philos == 1)
	{
		lonely_philo_routine(philo);
		return (NULL);
	}
	if (philo->philo_id % 2 == 0)
		righty_routine(philo);
	else
	{
		usleep(1000);
		lefty_routine(philo);
	}
	return (NULL);
}

void	lonely_philo_routine(t_philosopher *philo)
{
	long long	last_time_ate;

	pthread_mutex_lock(&(philo->ctx->mutex_l_t_a));
	last_time_ate = gettimeofday_in_ms();
	philo->last_time_ate = last_time_ate;
	pthread_mutex_unlock(&(philo->ctx->mutex_l_t_a));
	take_a_right_fork(philo);
	think(philo);
	while (1)
	{
		pthread_mutex_lock(&(philo->ctx->mutex_stop));
		if (philo->ctx->stop == 1)
		{
			pthread_mutex_unlock(&(philo->ctx->mutex_stop));
			return ;
		}
		pthread_mutex_unlock(&(philo->ctx->mutex_stop));
	}
	return ;
}

void	righty_routine(t_philosopher *philo)
{
	long long	last_time_ate;

	pthread_mutex_lock(&(philo->ctx->mutex_l_t_a));
	last_time_ate = gettimeofday_in_ms();
	philo->last_time_ate = last_time_ate;
	pthread_mutex_unlock(&(philo->ctx->mutex_l_t_a));
	while (1)
	{
		pthread_mutex_lock(&(philo->ctx->mutex_stop));
		if (philo->ctx->stop == 1)
		{
			pthread_mutex_unlock(&(philo->ctx->mutex_stop));
			break ;
		}
		pthread_mutex_unlock(&(philo->ctx->mutex_stop));
		think(philo);
		take_a_right_fork(philo);
		take_a_left_fork(philo);
		eat(philo);
		get_some_sleep(philo);
	}
	return ;
}

void	lefty_routine(t_philosopher *philo)
{
	long long	last_time_ate;

	pthread_mutex_lock(&(philo->ctx->mutex_l_t_a));
	last_time_ate = gettimeofday_in_ms();
	philo->last_time_ate = last_time_ate;
	pthread_mutex_unlock(&(philo->ctx->mutex_l_t_a));
	while (1)
	{
		pthread_mutex_lock(&(philo->ctx->mutex_stop));
		if (philo->ctx->stop == 1)
		{
			pthread_mutex_unlock(&(philo->ctx->mutex_stop));
			break ;
		}
		pthread_mutex_unlock(&(philo->ctx->mutex_stop));
		think(philo);
		take_a_left_fork(philo);
		take_a_right_fork(philo);
		eat(philo);
		get_some_sleep(philo);
	}
	return ;
}
