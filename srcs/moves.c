/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 16:51:00 by mgonon            #+#    #+#             */
/*   Updated: 2017/10/24 17:31:57 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	go_top(t_blcf blcf, int dir)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (y < blcf.map_h)
	{
		x = (dir == LEFT) ? 0 : blcf.map_w - 1;
		while ((dir == LEFT) ? x < blcf.map_w : x >= 0)
		{
			if (is_placeable(blcf, y, x))
			{
				ft_printf("%d %d\n", y, x);
				play(&blcf);
			}
			dir == LEFT ? x++ : x--;
			count++;
		}
		y++;
	}
	ft_printf("0 0\n");
}

static void	go_bot(t_blcf blcf, int dir)
{
	int	y;
	int	x;
	int	count;

	y = blcf.map_h - 1;
	count = 0;
	while (y >= 0)
	{
		x = (dir == LEFT) ? 0 : blcf.map_w - 1;
		while ((dir == LEFT) ? x < blcf.map_w : x >= 0)
		{
			if (is_placeable(blcf, y, x))
			{
				ft_printf("%d %d\n", y, x);
				play(&blcf);
			}
			dir == LEFT ? x++ : x--;
			count++;
		}
		y--;
	}
	ft_printf("0 0\n");
}

static void	go_mid(t_blcf blcf, int dir)
{
	int	y;
	int	x;

	y = blcf.map_h / 2;
	while (y >= 0)
	{
		x = (dir == LEFT) ? 0 : blcf.map_w - 1;
		while ((dir == LEFT) ? x < blcf.map_w : x >= 0)
		{
			if (is_placeable(blcf, y, x))
			{
				ft_printf("%d %d\n", y, x);
				play(&blcf);
			}
			else
				dir == LEFT ? x++ : x--;
		}
		y--;
		if (dir == RIGHT && y == 0 && x == 0)
			go_top(blcf, RIGHT);
	}
	if (dir == LEFT)
		go_bot(blcf, RIGHT);
}

void		do_moves(t_blcf *blcf, int dir)
{
	int	ret;

	if (!am_i_bot(*blcf))
		go_bot(*blcf, dir);
	else if (!am_i_top(*blcf))
		go_top(*blcf, dir);
	else
	{
		ret = where_i_go(*blcf);
		if (ret == TOP)
			go_top(*blcf, dir);
		else if (ret == BOT)
			go_bot(*blcf, dir);
		else
			go_mid(*blcf, dir);
	}
}
