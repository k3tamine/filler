/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 04:11:26 by mgonon            #+#    #+#             */
/*   Updated: 2017/09/02 05:47:32 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	g_x;
int	g_y;

static void	place_piece(t_piece piece)
{
	int	diff_x;
	int	diff_y;
	
	diff_x = piece.f_width - piece.p_width;
	diff_y = piece.f_height - piece.p_height;
	// fprintf(stderr, "%d %d", g_x - diff_x, g_y - diff_y);
	printf("%d %d", g_y - diff_y, g_x - diff_x);
	// printf("8 2");
}

static int	is_placable(t_piece piece, t_board board)
{
	// fprintf(stderr, "%d < %d ?\n", g_x + piece.f_width, board.width);
	// fprintf(stderr, "%d < %d ?\n", g_y + piece.f_height, board.height);
	if (g_x + piece.f_width <= board.width && g_y + piece.f_height <= board.height)
		return (1);
	return (0);
}

static void	get_sign(int p_nb, char *p_sign, char *p_sign_min)
{
	if (p_nb == 1)
	{
		*p_sign = 'O';
		*p_sign_min = 'o';
	}
	else if (p_nb == 2)
	{
		*p_sign = 'X';
		*p_sign_min = 'x';		
	}
}

void		play_move(t_board *board)
{
	char	p_sign;
	char	p_sign_min;

	get_sign(board->p_nb, &p_sign, &p_sign_min);
	g_x = -1;
	while (++g_x < board->height)
	{
		// fprintf(stderr, "\n");
		g_y = -1;
		while (++g_y < board->width)
		{
			// fprintf(stderr, "map = %c ", board->map[g_x][g_y]);
			if (board->map[g_x][g_y] == p_sign || board->map[g_x][g_y] == p_sign_min) // ||||||| p_sign_min
				if (is_placable(board->piece, *board))
				{
					place_piece(board->piece);
					exit(1) ;
				}
		}
	}
	printf("0 0");
}