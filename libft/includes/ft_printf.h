/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:43:57 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/26 18:06:10 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <locale.h>
# include <fcntl.h>

enum {MINUS = 1, PLUS = 2, HASH = 4, ZERO = 8, DOT = 16,
	MFIELD = 32, SPACE = 64, DEC = 128, L = 256, LL = 512, J = 1024, Z = 2048,
	H = 4096, HH = 8192, STOP = 16384, AP = 32768};
typedef	struct		s_info
{
	char			type;
	int				cmd_size;
	unsigned int	flgs;
	int				mfield;
	int				prec;
	int				s_ct[3];
	int				nbr_l;
	int				nbr_h;
}					t_info;
char				*bonus_part(va_list ***arg, t_info **data);
char				*binairy_spec(va_list ****arg, t_info ***data);
int					buff_rend(char *s, int len, int wrt);
int					data_init(va_list **arg, t_info *data, char *s);
void				new_data(t_info **data);
char				*chr_manager(va_list **arg, t_info *data);
char				*nbr_manager(va_list **arg, t_info *data);
unsigned int		pars_check(t_info **data, char t, unsigned int sv);
void				fl_ps(t_info **data, int size, int ch, unsigned int sv);
char				*flag_apos(char *s, int *size, int oth);
char				*flag_hash(int size, char *s, t_info *data);
void				flag_manager(t_info *data, char *s, int size);
void				flag_mfield_chr(int size, t_info *data, char *s,
	unsigned int sv);
char				*flag_prec(int prec, char *s, int size);
char				*flag_prec_chr(int prec, char *s, int size);
int					flag_sign(t_info *data, unsigned int sv, int ret);
void				flag_mfield_nbr(int size, t_info *data, char *s,
	unsigned int sv);
char				*ft_itoall(long long int n, int base, int size, int *sign);
char				*ft_utoall(unsigned long long int n, int base, int size,
	int sign);
char				*ft_strfill(char *s, char c, int len);
char				*ft_strdecal(char *d, char *s, int decl, int len);
char				*ft_strcpy_dir(char *d, char *s, int dir, int start);
void				nbr_cmp(void);
char				*uni_conv(wchar_t *w, t_info *data, int spe, int y);
int					uni_size(wchar_t w);
char				*uni_trans_2(wchar_t w, char *tmp);
void				wildcard_calc(va_list ***arg, t_info **data, int ct);
int					ft_printf(char *s, ...);

#endif
