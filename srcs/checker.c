/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 16:50:54 by mgonon            #+#    #+#             */
/*   Updated: 2017/10/25 17:23:05 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	is_in_map(t_blcf blcf, int x, int y)
{
	if (x + blcf.forme_w > blcf.map_w)
		return (0);
	else if (y + blcf.forme_h > blcf.map_h)
		return (0);
	else
		return (1);
}

int			is_placeable(t_blcf blcf, int y, int x)
{
	int	xt;
	int	yt;
	int	count;

	if (!is_in_map(blcf, x, y))
		return (0);
	yt = 0;
	count = 0;
	while (yt + y < blcf.map_h && yt < blcf.forme_h)
	{
		xt = 0;
		while (xt + x < blcf.map_w && xt < blcf.forme_w)
		{
			if (blcf.map[y + yt][x + xt] != '.' && blcf.piece[yt][xt] == '*')
				count++;
			if (blcf.map[y + yt][x + xt] != blcf.p_char &&
				blcf.piece[yt][xt] == '*' && blcf.map[y + yt][x + xt] != '.')
				return (0);
			xt++;
		}
		yt++;
	}
	return (count != 1 ? 0 : 1);
}

int			am_i_top(t_blcf blcf)
{
	int	x;
	int	y;
	int	count_opp;
	int	count_me;

	y = -1;
	count_opp = 0;
	count_me = 0;
	if (ft_strchr(blcf.map[0], blcf.p_char) != NULL)
		return (1);
	while (++y < blcf.map_h / 4)
	{
		x = -1;
		while (++x < blcf.map_w)
		{
			if (blcf.map[y][x] == blcf.p_char)
				++count_me;
			else if (blcf.map[y][x] == blcf.opp_char)
				++count_opp;
		}
	}
	if (count_me < count_opp || ft_strchr(blcf.map[0], blcf.p_char) == NULL)
		return (0);
	return (1);
}

int			am_i_bot(t_blcf blcf)
{
	int	x;
	int	y;
	int	count_opp;
	int	count_me;

	y = (blcf.map_h - blcf.map_h / 4) - 1;
	count_opp = 0;
	count_me = 0;
	if (ft_strchr(blcf.map[blcf.map_h - 1], blcf.p_char) != NULL)
		return (1);
	while (++y < blcf.map_h)
	{
		x = -1;
		while (++x < blcf.map_w)
		{
			if (blcf.map[y][x] == blcf.p_char)
				++count_me;
			else if (blcf.map[y][x] == blcf.opp_char)
				++count_opp;
		}
	}
	if (count_me < count_opp ||
		ft_strchr(blcf.map[blcf.map_h - 1], blcf.p_char) == NULL)
		return (0);
	return (1);
}

int			where_i_go(t_blcf blcf)
{
	int	y;

	y = -1;
	while (++y < blcf.map_h)
	{
		if (ft_strchr(blcf.map[y], blcf.opp_char) == NULL)
		{
			if (y < blcf.map_h / 3)
				return (TOP);
			else if (y > (blcf.map_h / 3) * 2)
				return (BOT);
			else
				return (MID);
		}
	}
	return (1);
}
