/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:46:58 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/02/24 09:35:32 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	create_threads(t_ctx *ctx)
{
	int			i;
	pthread_t	*philo_threads;
	pthread_t	monitor_thread;

	i = 0;
	philo_threads = malloc(sizeof(pthread_t) * ctx->num_philos);
	if (philo_threads == NULL)
		return (0);
	while (i < ctx->num_philos)
	{
		if (pthread_create(&philo_threads[i], NULL, start_routine,
				&(ctx->philos)[i]) != 0)
			return (threads_create_failed(ctx, philo_threads, i));
		i++;
	}
	if (pthread_create(&monitor_thread, NULL, monitor, ctx) != 0)
		return (threads_create_failed(ctx, philo_threads, ctx->num_philos));
	pthread_join(monitor_thread, NULL);
	i = 0;
	while (i < ctx->num_philos)
		pthread_join(philo_threads[i++], NULL);
	free(philo_threads);
	return (1);
}

int	create_insatiable_philos(char **argv, int argc)
{
	t_ctx	*ctx;

	ctx = NULL;
	if (init_ctx(&ctx, argv, argc) != 1)
		return (0);
	ctx->philos = init_philos(ctx->num_philos, ctx);
	if (ctx->philos == NULL)
		return (0);
	if (create_threads(ctx) == 0)
		return (0);
	clean(ctx);
	return (1);
}
