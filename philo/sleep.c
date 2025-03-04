/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:07:17 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/02/24 20:45:29 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <sys/time.h>

void	get_some_sleep(t_philosopher *philo)
{
	int			i;
	long long	time;

	i = 0;
	time = gettimeofday_in_ms();
	print_sleep(philo, time);
	while (i < (philo->ctx->time_to_sleep))
	{
		usleep(909);
		i++;
	}
}
