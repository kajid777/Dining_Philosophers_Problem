/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ctx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:18:47 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/02/24 21:00:13 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	set_mutex(t_ctx *ctx)
{
	if (pthread_mutex_init(&(ctx->mutex_printf), NULL) != 0)
	{
		printf("Error, mutex init failed\n");
		return (0);
	}
	if (pthread_mutex_init(&(ctx->mutex_l_t_a), NULL) != 0)
	{
		destroy_mutex_1(ctx, 1);
		printf("Error, mutex init failed\n");
		return (0);
	}
	if (pthread_mutex_init(&(ctx->mutex_meals_count), NULL) != 0)
	{
		destroy_mutex_1(ctx, 2);
		printf("Error, mutex init failed\n");
		return (0);
	}
	if (pthread_mutex_init(&(ctx->mutex_stop), NULL) != 0)
	{
		destroy_mutex_1(ctx, 3);
		printf("Error, mutex init failed\n");
		return (0);
	}
	return (1);
}

int	set_args_param(t_ctx *ctx, char **argv, int argc)
{
	ctx->num_philos = ft_atoi(argv[1]);
	ctx->time_to_die = ft_atoi(argv[2]);
	ctx->time_to_eat = ft_atoi(argv[3]);
	ctx->time_to_sleep = ft_atoi(argv[4]);
	if (ctx->num_philos < 1 || ctx->time_to_die < 0 || ctx->time_to_eat < 0
		|| ctx->time_to_sleep < 0)
	{
		printf("Error, wrong arguments\n");
		free(ctx);
		return (0);
	}
	if (argc == 6)
	{
		ctx->eating_capacity = ft_atoi(argv[5]);
		if (ctx->eating_capacity < 1)
		{
			printf("Error, wrong arguments\n");
			free(ctx);
			return (0);
		}
	}
	else
		ctx->eating_capacity = -1;
	return (1);
}

int	init_ctx(t_ctx **ctx, char **argv, int argc)
{
	*ctx = malloc(sizeof(t_ctx));
	if (!(*ctx))
		ctx_malloc_failed();
	if (set_args_param(*ctx, argv, argc) != 1)
		return (0);
	(*ctx)->full_philos = 0;
	(*ctx)->stop = 0;
	if (set_mutex(*ctx) != 1)
		return (0);
	return (1);
}
