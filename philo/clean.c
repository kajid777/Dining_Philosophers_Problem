/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:17:31 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/02/24 16:03:12 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	clean(t_ctx *ctx)
{
	destroy_mutex_2(ctx);
	destroy_mutex_forks(ctx);
	free(ctx->philos);
	free(ctx);
	return (1);
}
