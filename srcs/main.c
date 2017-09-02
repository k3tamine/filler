/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 17:00:19 by mgonon            #+#    #+#             */
/*   Updated: 2017/09/02 05:45:50 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	main(void)
{
	t_board	board;

	ft_bzero(&board, sizeof(board));
	parse_vm_info(&board);
	play_move(&board);
	// printf("3 3");
	return (0);
}