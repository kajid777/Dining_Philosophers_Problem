/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_a_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:10:22 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/02/24 20:46:29 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	take_a_right_fork(t_philosopher *philo)
{
	long long	time;

	pthread_mutex_lock(philo->mutex_right_fork);
	time = gettimeofday_in_ms();
	print_fork(philo, time);
}

void	take_a_left_fork(t_philosopher *philo)
{
	long long	time;

	pthread_mutex_lock(philo->mutex_left_fork);
	time = gettimeofday_in_ms();
	print_fork(philo, time);
}
