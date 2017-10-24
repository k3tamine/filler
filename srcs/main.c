/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 16:51:21 by mgonon            #+#    #+#             */
/*   Updated: 2017/10/24 17:04:36 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	parse_piece_size(t_blcf *blcf, char *piece_info)
{
	char	**piece_split;
	int		i;

	i = 0;
	piece_split = ft_strsplit(piece_info, ' ');
	blcf->forme_h = ft_atoi(piece_split[1]);
	blcf->forme_w = ft_atoi(piece_split[2]);
}

static void	parse_piece(t_blcf *blcf, char *first_line)
{
	int	i;

	i = 0;
	parse_piece_size(blcf, first_line);
	blcf->piece = (char **)malloc(sizeof(char *) * (blcf->forme_h + 1));
	while (i < blcf->forme_h)
	{
		get_next_line(0, &first_line);
		blcf->piece[i] = ft_strdup(first_line);
		i++;
	}
	blcf->piece[blcf->forme_h] = NULL;
}

void		play(t_blcf *blcf)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (line[0] == '0' && line[1] == '0' && line[2] == '0')
			get_map(line, blcf);
		if (ft_strstr(line, "Piece"))
		{
			parse_piece(blcf, line);
			free(line);
			break ;
		}
		free(line);
	}
	if (blcf->first == 0)
		blcf->top = am_i_top(*blcf);
	blcf->top ? do_moves(blcf, LEFT) : do_moves(blcf, RIGHT);
}

int			main(void)
{
	t_blcf	blcf;
	char	*line;

	blcf.first = 0;
	get_next_line(0, &line);
	get_player_info(line, &blcf);
	free(line);
	get_next_line(0, &line);
	get_board_size(line, &blcf.map_h, &blcf.map_w);
	free(line);
	blcf.map = malloc_map(blcf.map_h, blcf.map_w);
	play(&blcf);
	return (0);
}
