/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vm_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:33:01 by mgonon            #+#    #+#             */
/*   Updated: 2017/10/25 17:48:13 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char	**malloc_map(int height, int width)
{
	char	**map;
	int		i;

	i = -1;
	map = (char **)malloc(sizeof(char *) * height + 1);
	while (++i < height)
		map[i] = (char *)malloc(sizeof(char) * width + 1);
	map[height] = NULL;
	return (map);
}

void	get_map(char *line, t_blcf *blcf)
{
	int y;

	y = 0;
	while (y < blcf->map_h)
	{
		ft_strcpy(blcf->map[y], line + 4);
		blcf->map[y][blcf->map_w] = '\0';
		if (y)
			free(line);
		if (y < blcf->map_h - 1)
			get_next_line(0, &line);
		++y;
	}
	blcf->map[y] = 0;
}

void	get_size(char *line, int *height, int *width)
{
	while (*line != ' ' && *line)
		++line;
	if (!*line)
		exit(1);
	++line;
	*height = ft_atoi(line);
	while (*line != ' ' && *line)
		++line;
	if (!*line)
		exit(1);
	++line;
	*width = ft_atoi(line);
}

void	get_player_info(char *line, t_blcf *blcf)
{
	while (*line != 'p')
		++line;
	if (*line)
	{
		++line;
		if (ft_atoi(line) == 1)
		{
			blcf->p_char = 'O';
			blcf->opp_char = 'X';
		}
		else
		{
			blcf->p_char = 'X';
			blcf->opp_char = 'O';
		}
	}
}
