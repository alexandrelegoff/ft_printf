/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 18:13:49 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/07 01:09:30 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

int			ft_printf(const char *fmt, ...)
{
	va_list		args;
	t_list		*lst;
	char		buf[4096];
	int			len;

	len = 0;
	va_start(args, fmt);
	lst = elem_list(fmt, buf, &len, args);
	len += list_size(lst);
	print_list(lst);
	delete_list(&lst);
	return (len);
}

t_list		*elem_list(const char *fmt, char *buf, int *len, va_list args)
{
	char	*arr;
	t_flags	*flags;
	t_list	*lst;
	int		i;

	init_beg(&lst, &i);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			get_values(buf, i, &fmt, &flags);
			append(&lst, buf, i);
			init_values(&i, &arr);
			arr = choose_conversion(flags, fmt, args);
			assign_value(fmt, &flags, &lst, &arr);
			valid_free(len, flags, &arr, &lst);
		}
		else
			non_conversion(fmt, buf, &i);
		renew(len, &fmt, &lst, flags);
	}
	buf[i] = '\0';
	append(&lst, buf, i);
	return (lst);
}
//
//int 	main()
//{
////	ft_printf("'%-05d'\n", -42);
////	printf("'%-05d'\n", -42);
////	ft_printf("%-10s is a string\n", "");
////	printf("%-10s is a string\n", "");
//	ft_printf("%s %c\n", NULL, 0);
//	printf("%s %c\n", NULL, 0);
//	ft_printf("%s %c\n", NULL, 0);
//	printf("%s %c\n", NULL, 0);	ft_printf("%s %c\n", NULL, 0);
//	printf("%s %c\n", NULL, 0);	ft_printf("%s %c\n", NULL, 0);
//	printf("%s %c\n", NULL, 0);	ft_printf("%s %c\n", NULL, 0);
//	printf("%s %c\n", NULL, 0);
//	while (1);
//
//}