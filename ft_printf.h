/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 18:16:09 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/07 00:07:40 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <string.h>
# include <wchar.h>
#include <limits.h>

typedef struct          s_flags
{
    int     hash;
    int     o_flag;
    int     minus;
    int     plus;
	int		space;
	int		numbers;
  int   double_h;
  int   one_h;
  int   one_l;
  int   double_l;
  int   one_j;
  int   one_z;
  int	width;
  int	precision;
  int dot;
  int len;
  int len_total;
  int zeros;
}                       t_flags;

int			ft_printf(const char *format, ...);
int			ft_putstr(const char *str);
int			ft_putchar(char c);
int			ft_putnbr(int n);
int			ft_puthex(unsigned long n, char upper);
int			ft_putunsigned(unsigned int n);
int			ft_putoctal(unsigned int n);
char *conversion(const char *str, va_list args);
t_flags		*init_list();
int			find_flags(t_flags *flags, const char **str);
char *	choose_conversion(t_flags *flags, const char *str, va_list args);
void		parse_args(t_flags **flags, const char **fmt);
int		validate_percentage(char c);
int		validate_flags(char c);
int     validate_modifier(char c);
void	parse_args_modifier(t_flags **flags, const char **fmt);
int		validate_precision(char c);
void	parse_args_precision(t_flags **flags, const char **fmt);
int		is_number(char c);
char	*ft_itoa_base(unsigned long long value, unsigned char base, char upper);
char	*ft_itoa_base_signed(long long value, unsigned char base, char upper);
void	append(t_list **head_ref, char *new_data, int content_size);
int   hash_flags(t_list **lst, const char *fmt, char **arr);
void	print_list(t_list *lst);
void	push(t_list** head_ref, char *new_data);
void	parse_everything(t_flags **flags, const char **fmt);
int		plus_flags(t_list **lst);
int		handle_flags(t_list **lst, t_flags *flags, va_list args);
void	delete_list(t_list **head_ref);
void	append_char(t_list **head_ref, char new_data, int content_size);
int		list_size(t_list *lst);
int		width(t_list **lst, t_flags *flags, char **arr, const char *fmt);
int 	handle_flags2(t_list **lst, t_flags *flags, char **arr, const char *fmt);
int 	precision_handle(t_list **lst, t_flags *flags, char **arr);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *dest, const char *src);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
void  ft_strdel(char **as);
void  reverse(t_list **lst);
int 	is_carac(char c);
void	value_negative(char **arr, t_list **lst, t_flags **flags);
void	value_zero(char **arr, t_flags **flags);

#endif