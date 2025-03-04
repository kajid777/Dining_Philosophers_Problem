/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:38:19 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/02/26 11:39:13 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_meals_count(t_ctx *ctx)
{
	int	i;

	if (ctx->eating_capacity == -1)
		return (0);
	i = 0;
	while (i < ctx->num_philos)
	{
		pthread_mutex_lock(&(ctx->mutex_meals_count));
		if (ctx->philos[i].meals_count >= ctx->eating_capacity)
			ctx->full_philos++;
		pthread_mutex_unlock(&(ctx->mutex_meals_count));
		i++;
	}
	if (ctx->full_philos >= ctx->num_philos)
	{
		pthread_mutex_lock(&(ctx->mutex_stop));
		ctx->stop = 1;
		pthread_mutex_unlock(&(ctx->mutex_stop));
		return (1);
	}
	ctx->full_philos = 0;
	return (0);
}

void	init_last_time_ate(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->num_philos)
	{
		pthread_mutex_lock(&(ctx->mutex_l_t_a));
		ctx->philos[i].last_time_ate = gettimeofday_in_ms();
		pthread_mutex_unlock(&(ctx->mutex_l_t_a));
		i++;
	}
}

int	is_dead(t_ctx *ctx, int i)
{
	long long	current_time;
	long long	time_diff;

	current_time = gettimeofday_in_ms();
	pthread_mutex_lock(&(ctx->mutex_l_t_a));
	time_diff = current_time - ctx->philos[i].last_time_ate;
	pthread_mutex_unlock(&(ctx->mutex_l_t_a));
	if (time_diff > ctx->time_to_die)
		return (1);
	else
		return (0);
}

void	has_gone_to_valhalla(t_ctx *ctx, int i)
{
	pthread_mutex_lock(&(ctx->mutex_stop));
	ctx->stop = 1;
	pthread_mutex_unlock(&(ctx->mutex_stop));
	print_die(ctx, i);
}

void	*monitor(void *arg)
{
	int		i;
	t_ctx	*ctx;

	ctx = arg;
	init_last_time_ate(ctx);
	while (1)
	{
		i = 0;
		while (i < ctx->num_philos)
		{
			if (is_dead(ctx, i))
			{
				has_gone_to_valhalla(ctx, i);
				return (NULL);
			}
			i++;
		}
		if (check_meals_count(ctx))
			return (NULL);
	}
	return (NULL);
}
