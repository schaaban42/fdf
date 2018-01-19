/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:08:13 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/08 14:28:00 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# define BUFF_SIZE	42

typedef struct	s_line
{
	int				fd;
	char			*content;
	struct s_line	*next;
}				t_line;

int				get_next_line(const int fd, char **line);

#endif
