/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a2ddel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:27:41 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/19 14:32:55 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_a2ddel(void **array)
{
	int		i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_memdel((void**)&array[i]);
		i++;
	}
	ft_memdel((void**)&array);
	return ;
}
