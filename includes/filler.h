/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 17:20:09 by mgonon            #+#    #+#             */
/*   Updated: 2017/09/01 08:22:45 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_piece
{
	int	width;
	int	height;
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
