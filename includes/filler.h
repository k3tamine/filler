/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 16:51:14 by mgonon            #+#    #+#             */
/*   Updated: 2017/10/25 17:17:05 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define TOP	42
# define BOT	43
# define MID	44
# define LEFT	45
# define RIGHT	46
# include "../libft/libft.h"

typedef struct	s_blcf
{
	int		map_h;
	int		map_w;
	int		forme_h;
	int		forme_w;
	int		top;
	int		first;
	char	p_char;
	char	opp_char;
	char	**map;
	char	**piece;
}				t_blcf;

int				is_placeable(t_blcf blcf, int x, int y);
int				am_i_top(t_blcf blcf);
int				am_i_bot(t_blcf blcf);
void			play(t_blcf *blcf);
int				parse_vm_info(t_blcf *blcf);
void			get_player_info(char *line, t_blcf *blcf);
void			get_size(char *line, int *height, int *width);
void			get_map(char *line, t_blcf *blcf);
int				where_i_go(t_blcf blcf);
void			do_moves(t_blcf *blcf, int dir);
void			print_map(char **map);
char			**malloc_map(int height, int width);
void			free_tab(char **tab);

#endif
