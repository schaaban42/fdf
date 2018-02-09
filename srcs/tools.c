/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 21:33:29 by schaaban          #+#    #+#             */
/*   Updated: 2018/02/09 15:27:03 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

int		str_is_valid(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != ',' && str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	if (str[i++] == '\0')
		return (1);
	if (str[i++] != '0')
		return (0);
	if (str[i++] != 'x')
		return (0);
	j = i;
	while (j < i + 6)
	{
		if (!ft_isdigit_base(str[j++], 16))
			return (0);
	}
	return ((str[j] != '\0') ? 0 : 1);
}
