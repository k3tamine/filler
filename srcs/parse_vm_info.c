/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vm_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 06:08:05 by mgonon            #+#    #+#             */
/*   Updated: 2017/09/02 06:08:24 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	g_x = 0;

static void	get_str_piece(char *line, t_piece *piece)
{

	piece->str = (char *)malloc(sizeof(char) * piece->f_height * piece->f_width + piece->f_height + 1);
	ft_strcpy(piece->str, line);
	piece->str += ft_strlen(line);
	*(piece->str) = '\n';
	(piece->str)++;

	fprintf(stderr, "piece->str = %s\n", piece->str);
}

static void	get_piece(char *line, t_piece *piece)
{
	int	height;
	int	width;
	int	max;

	width = 0;
	max = 0;
	while (*line != ' ')
		line++;
	height = ft_atoi(line);
	piece->f_height = ft_atoi(line);
	piece->f_width = ft_atoi(line + 2);
	while (height-- > 0)
	{
		get_next_line(0, &line);
		while (*line == '.' || *line == '*')
		{
			if (*line == '*')
				width += 1;
			line++;
		}
		if (width > max)
			piece->p_width = width;
		if (width != 0)
			piece->p_height += 1;
		width = 0;
	}
}

static void	get_map(char *line, char **map, int board_width)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (*line != ' ')
		line++;
	line++;
	while (i++ < board_width)
	{
		map[g_x][y] = *line;
		++y;
		line++;
	}
	map[g_x][y] = '\0';
	++g_x;
}

static void	get_board_size(char *line, int *height, int *width)
{
	while (*line != ' ')
		++line;
	++line;
	*height = ft_atoi(line);
	while (*line != ' ')
		++line;
	++line;
	*width = ft_atoi(line);
}

static int	get_p_nb(char *line)
{
	while (*line != 'p')
		++line;
	if (*line)
	{
		++line;
		return (ft_atoi(line));
	}
	return (-42);
}

static char	**malloc_map(t_board board)
{
	char	**map;
	int		i;

	i = -1;
	map = (char **)malloc(sizeof(char *) * board.height);
	while (++i < board.height)
		map[i] = (char *)malloc(sizeof(char) * board.width + 1);
	return (map);
}

int			parse_vm_info(t_board *board)
{
	char	*line;
	int		fd;

	if (!(fd = open("toto", O_RDWR)))
		return (42);
	line = ft_strnew(10000);
	while (get_next_line(0, &line))
	{
		if (!board->p_nb)
			board->p_nb = get_p_nb(line);
		else if (!board->height || !board->width)
		{
			get_board_size(line, &(board->height), &(board->width));
			board->map = malloc_map(*board);
		}
		else if (ft_strstr(line, "Piece"))
		{
			get_piece(line, &(board->piece));
			break ;
		}
		else if (ft_atoi(line) >= 0 && ft_atoi(line) < board->height)
			get_map(line, board->map, board->width);
	}
	free(line);
	fprintf(stderr, "\n======== INFOS ========\n");
	fprintf(stderr, "p_nb = %d\n", board->p_nb);
	fprintf(stderr, "board->width = %d\n", board->width);
	fprintf(stderr, "board->height = %d\n", board->height);
	fprintf(stderr, "p.p_width = %d\n", board->piece.p_width);
	fprintf(stderr, "p.p_height = %d\n", board->piece.p_height);
	fprintf(stderr, "========= END =========\n\n");
	return (0);
}
