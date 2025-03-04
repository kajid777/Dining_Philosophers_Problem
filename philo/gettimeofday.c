/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettimeofday.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:58:47 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/02/24 09:21:31 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long long	gettimeofday_in_ms(void)
{
	struct timeval	tv;
	long long		time_in_ms;

	time_in_ms = 0;
	if (gettimeofday(&tv, NULL) == -1)
	{
		printf("Error, gettimeofday failed\n");
		return (-1);
	}
	time_in_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time_in_ms);
}
