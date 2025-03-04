/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:37:06 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/02/24 21:03:01 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	set_mutex_forks(t_ctx *ctx, int num_philos)
{
	int	i;

	i = 0;
	ctx->mutex_forks = malloc(sizeof(pthread_mutex_t) * num_philos);
	if (ctx->mutex_forks == NULL)
	{
		printf("Error, malloc failed\n");
		return (0);
	}
	while (i < num_philos)
	{
		if (pthread_mutex_init(&(ctx->mutex_forks[i]), NULL) != 0)
		{
			printf("Error, set_mutex_forks failed\n");
			return (set_mutex_forks_failed(ctx, i));
		}
		i++;
	}
	return (1);
}

void	set_philo_id(t_philosopher *philos, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		philos[i].philo_id = i;
		i++;
	}
}

void	set_count_meals(t_philosopher *philos, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		philos[i].meals_count = 0;
		i++;
	}
}

void	set_philo_ctx(t_philosopher *philos, t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->num_philos)
	{
		philos[i].ctx = ctx;
		i++;
	}
}
