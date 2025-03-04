/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:07:28 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/02/24 20:46:09 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	think(t_philosopher *philo)
{
	long long	time;

	time = 0;
	time = gettimeofday_in_ms();
	print_think(philo, time);
	return ;
}
