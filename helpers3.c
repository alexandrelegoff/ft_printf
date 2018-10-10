/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 23:46:53 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/09 23:46:54 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int		ft_putstr(const char *str)
{
	int i;

	i = -1;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}
