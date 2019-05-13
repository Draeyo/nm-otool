/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:37:37 by vlistrat          #+#    #+#             */
/*   Updated: 2016/09/01 13:36:17 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

# define TAG lst->tag
# define FLAG lst->flag
# define WIDTH lst->width
# define PREC lst->prec
# define MODIF lst->modif
# define CONV lst->conv
# define LEN lst->len
# define NEG lst->neg
# define HEX lst->hex
# define ZEROF lst->zeroflag
# define ZEROP lst->zeroprec
# define COUNT lst->count
# define MIN lst->min
# define WSTR lst->wstr
# define WC lst->wc
# define WDT lst->wdt
# define PRC lst->prc
# define STR lst->str

/*
** strcture principale
*/
typedef struct		s_print
{
	char			*tag;
	char			*flag;
	int				width;
	int				prec;
	char			*modif;
	char			conv;
	int				len;
	int				neg;
	char			*hex;
	int				zeroflag;
	int				zeroprec;
	int				count;
	char			*str;
	wchar_t			*wstr;
	wchar_t			wc;
	int				min;
	char			*wdt;
	char			*prc;
}					t_print;

/*
** fonction principale
*/
int					ft_printf(const char *format, ...);

/*
** envoi vers fonction de conv correspondante
*/
int					ft_tag(va_list ap, t_print *lst);

/*
** fonctions de recuperation argument et conversion
*/
int					ft_conv_s(va_list ap, t_print *lst);
int					ft_conv_d(va_list ap, t_print *lst);
int					ft_conv_p(va_list ap, t_print *lst);
int					ft_conv_x(va_list ap, t_print *lst);
int					ft_conv_c(va_list ap, t_print *lst);
int					ft_conv_o(va_list ap, t_print *lst);
int					ft_conv_ws(va_list ap, t_print *lst);
int					ft_conv_wc(va_list ap, t_print *lst);
int					ft_conv_u(va_list ap, t_print *lst);
int					ft_noconv(t_print *lst);

/*
** conversions divers
*/
uintmax_t			ft_itoo(uintmax_t nb);
char				*ft_itohex(uintmax_t nb);
int					ft_s_atoi(char *str);
char				*ft_xtoa(intmax_t nb);
char				*ft_uxtoa(uintmax_t nb);

/*
** Utilitaires
*/
char				*ft_uitooa(uintmax_t nb);
char				*ft_strupper(char *str);
char				*ft_strrev(char *str);
int					ft_nblen(intmax_t nb);
int					ft_uxnblen(uintmax_t nb);
void				lst_init(t_print *lst);
int					ft_putwchar_fd(wchar_t c, int fd);
int					ft_putwstr_fd(wchar_t *wstr, int fd);
char				*ft_strnewcpy(char *str);
char				*ft_strcut(char *str, int n);
char				*ft_xupper(char *str);
char				*ft_strnew_digit(int nb, int fill);
int					ft_tag_error(t_print *lst, const char *format);
int					ft_plus(t_print *lst);
int					ft_ishex(t_print *lst);
int					ft_zeroflag(t_print *lst);
int					ft_zprec(t_print *lst, char *tag, int i);
void				ft_short_padneg(t_print *lst);
int					ft_spstr_min(t_print *lst);
int					ft_print(t_print *lst, char *str, int ret);
int					ft_wstrlen(wchar_t *wstr);
int					ft_putnwchar(wchar_t *str, int n);
void				free_all(t_print *lst);

/*
** strsub du % au tag de conversion
*/
int					ft_get_last(const char *format, int i);
char				*ft_get_tag(const char *format, int last);

/*
** recuperation du tag dans la structure
*/
int					ft_conv_tag(const char *format, t_print *lst);
int					ft_get_flag(char *tag, t_print *lst);
int					ft_get_width(char *tag, t_print *lst);
int					ft_get_prec(char *tag, t_print *lst);
int					ft_get_modif(char *tag, t_print *lst);
int					ft_get_conv(char *tag, t_print *lst);

/*
** verifications du flag
*/
int					ft_isconv(int c);
int					ft_ismod(int c);
int					ft_validmod(char *str);
int					ft_after_flag(int c);
int					ft_after_width(int c);
int					ft_after_prec(int c);
int					ft_is_c(t_print *lst);

/*
** Options
*/
char				*ft_width(t_print *lst, int len);
char				*ft_prec(t_print *lst, int len);
char				*ft_padding(char *width, char *prec, \
		char *elem, t_print *lst);
int					ft_padding_str(t_print *lst, char *str);
int					ft_padding_int(t_print *lst, intmax_t nb);
int					ft_padding_uint(t_print *lst, uintmax_t nb);

#endif
