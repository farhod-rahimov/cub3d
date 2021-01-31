/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:30:48 by btammara          #+#    #+#             */
/*   Updated: 2020/12/09 14:05:21 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int						ft_printf(const char *format, ...);

typedef	struct			s_struct
{
	char				*str_do_p;
	char				*flag;
	char				*flag2;
	char				*width;
	char				*precision;
	char				*type_of_arg;
	char				*arg;
	char				*result;
	struct s_struct		*next;
}						t_struct;

char					*ft_substr(char const *s,
		unsigned int start, size_t len);
long long int			ft_strlen(const char *s);
char					*ft_strdup(const char *s1);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strdup_char_like_str(const char c);
t_struct				*create_new_el(void);
char					*crt_spcs_c(int n);
char					*crt_symbls_s(int n, char c);
int						ft_atoi(const char *str);
char					*ft_itoa(long long int n);
char					*ft_16xtoa(long long int n);
char					*ft_toupper_str(char *str);
void					ft_putstr_fd(char *s, int fd);
int						ft_putstr_if_tmp_arg_null_term(char *arg,
		char *s, char *flag);

char					*ft_parse(char *format, t_struct **element);
char					*get_str_from_formatted_str(char *format, int i,
		t_struct **element);
char					*get_flag_from_formatted_str(char *format, int i,
		t_struct **element);
char					*get_width_from_formatted_str(char *format, int i,
		t_struct **element);
char					*get_precision_from_formatted_str(char *format, int i,
		t_struct **element);
char					*get_type_of_arg_from_formatted_str(char *format, int i,
		t_struct **element);
char					*get2_type_of_arg_from_formatted_str(char *format,
		int i, t_struct **element, int i_for_set);
void					free_struct(t_struct **element, t_struct *tmp_s1);

int						print_res_of_parser(char *format, int i);
int						redirect_to_appropriate_type(char type_of_arg,
		t_struct **element, va_list ap);
int						check_is_it_correct_element(t_struct **element);
int						is_there_something_to_print(t_struct **element,
		va_list ap);
int						print_result(t_struct **element);
int						work_with_prcnt1(char *format, int i,
		t_struct **element);
int						work_with_prcnt2(char *format, int i,
		t_struct **element, int kolvo_prcnt);
int						work_with_flag(char *format, int i, t_struct **element);
int						workkk_with_flag(char *format, int i,
		t_struct **element);
int						work_with_precision(char *format, int i,
		t_struct **element);

int						work_with_type_c(t_struct **element, va_list ap);
int						work_with_type_p(t_struct **element, va_list ap);
int						gget_width(t_struct **element, va_list ap);
int						gget_precision(t_struct **element, va_list ap);
int						wwork_with_precision(t_struct **element,
		int kolvo_nuley);

int						work_with_type_diu(t_struct **element, va_list ap);
int						wwork_with_precision_diu(t_struct **element,
		char *tmp, int kolvo_nuley, char *tmp1);
int						wwork0_with_flag_diu(t_struct **element,
		long int tmp_d, int kolvo_simvolov);
int						wwork1_with_flag_diu(t_struct **element,
		long int tmp_d, int kolvo_simvolov, char *tmp);
int						wwork2_with_flag_diu(t_struct **element,
		char *tmp);
int						wwork3_with_flag_diu(t_struct **element,
		long int tmp_d, int kolvo_simvolov, char *tmp);
int						wwork4_with_flag_diu(t_struct **element,
		int kolvo_simvolov, char *tmp);
int						wwork0_with_width_diu(t_struct **element,
		long int tmp_d, char *tmp, int kolvo_simvolov);
int						wwork1_with_width_diu(t_struct **element,
		long int tmp_d, char *tmp, int kolvo_simvolov);

int						work_with_type_p(t_struct **element, va_list ap);
int						wworkk_with_type_p(t_struct **element,
		char *tmp, int kolvo_simvolov);
int						wwork0_with_flag_p(t_struct **element,
		char *tmp, int kolvo_simvolov);
int						wwork1_with_flag_p(t_struct **element,
		char *tmp, int kolvo_simvolov);
int						wwork2_with_flag_p(t_struct **element,
		char *tmp, int kolvo_simvolov);
int						wwork22_with_flag_p(t_struct **element,
		char *tmp, int kolvo_simvolov);
int						wwork3_p(t_struct **element, char *tmp,
		int kolvo_simvolov);
int						wwork33_p(t_struct **element, char *tmp);

int						work_with_type_prcnt(t_struct **element, va_list ap);
int						wwork0_with_flag_prcnt(t_struct **element,
		char *tmp, int kolvo_simvolov, char *tmp1);
int						wwork0_with_width_prcnt(t_struct **element,
		char *tmp, int kolvo_simvolov);
int						wwork1_with_width_prcnt(t_struct **element, char *tmp);

int						work_with_type_s(t_struct **element, va_list ap);
int						ggget_width_s(t_struct **element, va_list ap,
		char *tmp);
int						ggget_precision_s(t_struct **element, va_list ap,
		char *tmp);
int						wwork0_with_flag_s(t_struct **element,
		char *tmp, int kolvo_simvolov);
int						wwork1_with_flag_s(t_struct **element,
		char *tmp, int kolvo_simvolov);
int						wwork2_with_precision_s(t_struct **element,
		char *tmp, int kolvo_simvolov);
int						wwork3_with_precision_s(t_struct **element,
		char *tmp, int kolvo_simvolov);
int						wwork4_with_precision_s(t_struct **element,
		char *tmp, int kolvo_simvolov);
int						wwork5_with_width_s(t_struct **element,
		char *tmp, int kolvo_simvolov);
int						wwork6_with_width_s(t_struct **element,
		char *tmp, int kolvo_simvolov);
int						work_s(t_struct **element, char *tmp);

int						work_with_type_x(t_struct **element, va_list ap);
int						wwork0_with_type_and_precision_x(t_struct **element,
		char *tmp, int kolvo_simvolov);
int						wwork0_with_flag_x(t_struct **element,
		char *tmp, int kolvo_simvolov);
int						wwork1_with_flag_x(t_struct **element,
		char *tmp, int kolvo_simvolov);
int						wwork2_with_flag_x(t_struct **element,
		char *tmp, int kolvo_simvolov);
int						wwork22_with_flag_x(t_struct **element,
		char *tmp, int kolvo_simvolov);
int						wwork3_with_width_x(t_struct **element,
		char *tmp, int kolvo_simvolov, char *tmp1);

#endif
