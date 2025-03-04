/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:06:55 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/02/24 21:00:43 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	destroy_mutex_forks(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->num_philos)
	{
		pthread_mutex_destroy(&(ctx->mutex_forks[i]));
		i++;
	}
	free(ctx->mutex_forks);
}

int	destroy_mutex_1(t_ctx *ctx, int flag)
{
	if (flag == 1)
	{
		pthread_mutex_destroy(&(ctx->mutex_printf));
	}
	else if (flag == 2)
	{
		pthread_mutex_destroy(&(ctx->mutex_printf));
		pthread_mutex_destroy(&(ctx->mutex_l_t_a));
	}
	else if (flag == 3)
	{
		pthread_mutex_destroy(&(ctx->mutex_printf));
		pthread_mutex_destroy(&(ctx->mutex_l_t_a));
		pthread_mutex_destroy(&(ctx->mutex_meals_count));
	}
	return (0);
}

int	destroy_mutex_2(t_ctx *ctx)
{
	pthread_mutex_destroy(&(ctx->mutex_printf));
	pthread_mutex_destroy(&(ctx->mutex_l_t_a));
	pthread_mutex_destroy(&(ctx->mutex_meals_count));
	pthread_mutex_destroy(&(ctx->mutex_stop));
	return (0);
}
