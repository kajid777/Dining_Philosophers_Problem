/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:44:54 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/02/24 20:56:47 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_think(t_philosopher *philo, long long time)
{
	pthread_mutex_lock(&(philo->ctx->mutex_printf));
	pthread_mutex_lock(&(philo->ctx->mutex_stop));
	if (philo->ctx->stop != 1)
		printf("%lld %d is thinking\n", time, philo->philo_id);
	pthread_mutex_unlock(&(philo->ctx->mutex_stop));
	pthread_mutex_unlock(&(philo->ctx->mutex_printf));
}

void	print_fork(t_philosopher *philo, long long time)
{
	pthread_mutex_lock(&(philo->ctx->mutex_printf));
	pthread_mutex_lock(&(philo->ctx->mutex_stop));
	if (philo->ctx->stop != 1)
		printf("%lld %d has taken a fork\n", time, philo->philo_id);
	pthread_mutex_unlock(&(philo->ctx->mutex_stop));
	pthread_mutex_unlock(&(philo->ctx->mutex_printf));
}

void	print_eat(t_philosopher *philo, long long time)
{
	pthread_mutex_lock(&(philo->ctx->mutex_printf));
	pthread_mutex_lock(&(philo->ctx->mutex_stop));
	if (philo->ctx->stop != 1)
		printf("%lld %d is eating\n", time, philo->philo_id);
	pthread_mutex_unlock(&(philo->ctx->mutex_stop));
	pthread_mutex_unlock(&(philo->ctx->mutex_printf));
}

void	print_sleep(t_philosopher *philo, long long time)
{
	pthread_mutex_lock(&(philo->ctx->mutex_printf));
	pthread_mutex_lock(&(philo->ctx->mutex_stop));
	if (philo->ctx->stop != 1)
		printf("%lld %d is sleeping\n", time, philo->philo_id);
	pthread_mutex_unlock(&(philo->ctx->mutex_stop));
	pthread_mutex_unlock(&(philo->ctx->mutex_printf));
}

void	print_die(t_ctx *ctx, int i)
{
	pthread_mutex_lock(&(ctx->mutex_printf));
	printf("%lld %d died\n", gettimeofday_in_ms(), i);
	pthread_mutex_unlock(&(ctx->mutex_printf));
}
