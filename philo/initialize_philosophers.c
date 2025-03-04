/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_philosophers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:32:05 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/02/24 21:05:10 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	recognize_left_fork(t_philosopher *philos, int num_philos,
		pthread_mutex_t *mutex_forks)
{
	int	i;

	i = 0;
	if (num_philos <= 1)
	{
		return ;
	}
	while (i < num_philos)
	{
		philos[i].mutex_left_fork = &(mutex_forks)[i];
		i++;
	}
}

void	recognize_right_fork(t_philosopher *philos, int num_philos,
		pthread_mutex_t *mutex_forks)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		if (i == 0)
		{
			philos[i].mutex_right_fork = &(mutex_forks)[num_philos - 1];
		}
		else
		{
			philos[i].mutex_right_fork = &(mutex_forks)[i - 1];
		}
		i++;
	}
}

t_philosopher	*init_philos(int num_philos, t_ctx *ctx)
{
	t_philosopher	*philos;

	philos = malloc(sizeof(t_philosopher) * num_philos);
	if (philos == NULL)
		return (malloc_philos_failed(ctx));
	set_philo_id(philos, ctx->num_philos);
	set_philo_ctx(philos, ctx);
	set_count_meals(philos, ctx->num_philos);
	if (set_mutex_forks(ctx, ctx->num_philos) == 0)
		return (NULL);
	recognize_left_fork(philos, ctx->num_philos, ctx->mutex_forks);
	recognize_right_fork(philos, ctx->num_philos, ctx->mutex_forks);
	ctx->philos = philos;
	return (philos);
}
