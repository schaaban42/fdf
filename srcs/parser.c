/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:55:13 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/28 16:58:59 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"

void		parse_file(t_fdf *fdf)
{
	char	*file_str;
	char	*file_line;

	file_str = NULL;
	while (get_next_line(fdf->fd, &line))
	{
		if (!(file_str = ft_strjoin_free(file_str, line)))
		{
			
		}
	}
}