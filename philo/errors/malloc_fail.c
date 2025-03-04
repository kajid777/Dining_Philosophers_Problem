/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_fail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:12:27 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/02/24 16:02:52 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	ctx_malloc_failed(void)
{
	printf("Error, malloc failed\n");
	return (0);
}

int	set_mutex_forks_failed(t_ctx *ctx, int fork_nums)
{
	int	i;

	i = 0;
	while (i <= fork_nums)
	{
		pthread_mutex_destroy(&(ctx->mutex_forks[i]));
		i++;
	}
	destroy_mutex_2(ctx);
	return (0);
}

t_philosopher	*malloc_philos_failed(t_ctx *ctx)
{
	destroy_mutex_2(ctx);
	return (NULL);
}

int	threads_create_failed(t_ctx *ctx, pthread_t *philo_threads, int num_threads)
{
	int	i;

	i = 0;
	while (i < num_threads)
	{
		pthread_detach(philo_threads[i]);
		i++;
	}
	free(philo_threads);
	destroy_mutex_2(ctx);
	destroy_mutex_forks(ctx);
	return (0);
}
