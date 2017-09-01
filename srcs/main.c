/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 17:00:19 by mgonon            #+#    #+#             */
/*   Updated: 2017/09/01 09:14:24 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	main(void)
{
	// char	*line;
	// int		fd;

	// fd = 0;

	// if (!(fd = open("toto", O_RDWR)))
	// 	return (1);
	// line = ft_strnew(100);
	// while (get_next_line(0, &line) > 0)
	// 	ft_putendl_fd(line, 2);
	parse_vm_info();
	return (0);
}