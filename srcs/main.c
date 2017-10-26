/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 16:51:21 by mgonon            #+#    #+#             */
/*   Updated: 2017/10/25 17:53:22 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab[i]);
	tab = NULL;
	free(tab);
}

static void	parse_piece(t_blcf *blcf, char *line)
{
	int	i;

	i = 0;
	get_size(line, &(blcf->forme_h), &(blcf->forme_w));
	blcf->piece = (char **)malloc(sizeof(char *) * (blcf->forme_h + 1));
	while (i < blcf->forme_h)
	{
		blcf->piece[i] = (char *)malloc(sizeof(char) * blcf->forme_w + 1);
		get_next_line(0, &line);
		ft_strcpy(blcf->piece[i], line);
		free(line);
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
	if (blcf->piece)
	{
		if (blcf->first == 0)
			blcf->top = am_i_top(*blcf);
		blcf->top ? do_moves(blcf, LEFT) : do_moves(blcf, RIGHT);
	}
}

int			main(void)
{
	t_blcf	blcf;
	char	*line;

	blcf.first = 0;
	get_next_line(0, &line);
	if (!ft_strstr(line, "$$$ exec p"))
		exit(1);
	get_player_info(line, &blcf);
	free(line);
	get_next_line(0, &line);
	if (!ft_strstr(line, "Plateau"))
		exit(1);
	get_size(line, &blcf.map_h, &blcf.map_w);
	free(line);
	blcf.map = malloc_map(blcf.map_h, blcf.map_w);
	play(&blcf);
	return (0);
}
