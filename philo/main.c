/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:30:31 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/02/24 09:22:10 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		create_insatiable_philos(argv, argc);
	}
	else
	{
		printf("Error, the number of arguments are wrong\n");
	}
	return (0);
}
