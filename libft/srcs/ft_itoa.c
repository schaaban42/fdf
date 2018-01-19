/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:02:59 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/15 17:52:42 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa(int n)
{
	char	*str;
	int		tab[10];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (n != 0 || i == 0)
	{
		tab[i] = n % 10;
		n = n / 10;
		i++;
	}
	if ((str =
		(char*)malloc(sizeof(char) * (i + ((tab[i - 1] < 0) ? 2 : 1)))) == NULL)
		return (NULL);
	if (tab[i - 1] < 0)
		str[j++] = '-';
	while (--i >= 0)
	{
		str[j++] = ((tab[i] < 0) ? (-tab[i]) : (tab[i])) + '0';
	}
	str[j] = '\0';
	return (str);
}
