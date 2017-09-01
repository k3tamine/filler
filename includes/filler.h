/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 17:20:09 by mgonon            #+#    #+#             */
/*   Updated: 2017/09/01 10:39:39 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct	s_piece
{
	int	p_width;
	int	p_height;
	int	f_width;
	int	f_height;
}				t_piece;

typedef struct	s_board
{
	char	**map;
	int		p_nb;
	int		width;
	int		height;
	t_piece	piece;
}				t_board;				

int			parse_vm_info(void);

#endif
