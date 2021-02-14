/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:53:50 by gna               #+#    #+#             */
/*   Updated: 2020/04/22 15:11:40 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>

int			ft_atoi(char *str);
int			ft_find_chr(char *str, char c);
void		ft_putchar(char c);
int			ft_putstr(char *str);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, const char *s2);
int			ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_toupper(int c);
int			ft_find_str(char *s1, char *s2);
int			last_chr(const char *str, char c);
int			ft_strcmp(const char *s1, const char *s2);
char		*append_front(char *str, char c, int num);
char		*append_leading_zero(char *s, int precision);
char		*align_to_left(char *s, int width);
int			width_asterisk_check(char *str, va_list ap);
int			precision_asterisk_check(char *str, va_list ap);
int			**decimal_flags_infos(char *str);
int			**decimal_format_specifier_infos(
			char *str, int asterisk_width, int asterisk_precision);
char		*str_without_sign(long long dec);
char		*append_sign(char *s, long long dec, int **infos);
char		*align_to_right_append_sign(char *s, int width, long long dec);
char		*set_decimal_result(char *s, int **infos, long long dec);
char		*formatting_decimal(char *str,
			int asterisk_width, int asterisk_precision, long long dec);
int			get_hex_mem_size_for_unsigned_longlong(unsigned long long int num);
char		*fill_hex_memory_for_unsigned_longlong(
			int size, unsigned long long int num);
char		*change_to_hexadecimal_for_unsigned_longlong(
			unsigned long long num);
int			**hex_flags_infos(char *str);
int			**hex_format_specifier_infos(
			char *str, int asterisk_width, int asterisk_precision);
char		*append_ox(
			char *s, int **infos, unsigned long long dec, int large_hex);
char		*align_to_right_append_ox(char *s, int width);
char		*set_hex_result(char *s, int **infos);
char		*check_large_hex(char *str, int large_hex);
char		*formatting_small_hexadecimal(char *str, int asterisk_width,
			int precision_width, unsigned long long dec);
char		*formatting_large_hexadecimal(char *str, int asterisk_width,
			int precision_width, unsigned long long dec);
long long	get_size_for_longlong(long long num);
char		*min_for_longlong(void);
char		*set_str_for_longlong(long long num);
char		*ft_itoa_for_longlong(long long num);
int			get_size_for_unsigned_longlong(unsigned long long num);
char		*ft_itoa_for_unsigned_longlong(unsigned long long int num);
int			**set_double(int size);
void		free_double(int **ptr);
int			**octal_flags_infos(char *str);
int			**octal_format_specifier_infos(
			char *str, int asterisk_width, int asterisk_precision);
int			get_oct_mem_size_for_unsigned_longlong(unsigned long long int num);
char		*fill_oct_memory_for_unsigned_longlong(
			int size, unsigned long long int num);
char		*change_to_octal_for_unsigned_longlong(unsigned long long int num);
char		*append_o(char *s, int **infos, unsigned long long dec);
char		*set_oct_result(char *s, int **infos);
char		*formatting_octal(char *str,
			int asterisk_width, int asterisk_precision, unsigned long long dec);
int			**unsigned_flags_infos(char *str);
int			**unsigned_format_specifier_infos(
			char *str, int asterisk_width, int asterisk_precision);
char		*set_unsigned_result(char *s, int **infos);
char		*formatting_unsigned(char *str,
			int asterisk_width, int asterisk_precision, unsigned long long dec);
int			precision_infos(char *str, int i, int asterisk_precision);
int			**width_infos(char *str, int i, int asterisk_width);
int			check_precision(char *str, int i);
int			**c_flags_infos(char *str);
int			**c_format_specifier_infos(char *str, int asterisk_width);
int			print_space(int num);
int			formatting_char(char *str, int asterisk_width, int c);
int			**str_flags_infos(char *str);
int			str_precision_infos(char *str, int i, int asterisk_precision);
int			**str_format_specifier_infos(
			char *str, int asterisk_width, int asterisk_precision);
char		*cut_str(char *str, int precision);
char		*set_str_result(char *s, int **infos);
char		*str_null(void);
char		*formatting_string(char *format,
			int asterisk_width, int asterisk_precision, char *str);
char		*decimal_conversion(
			char *str, int width, int precision, va_list ap);
char		*integer_conversion(
			char *str, int width, int precision, va_list ap);
char		*hexadecimal_large_conversion(
			char *str, int width, int precision, va_list ap);
char		*hexadecimal_small_conversion(
			char *str, int width, int precision, va_list ap);
char		*octal_conversion(
			char *str, int width, int precision, va_list ap);
char		*unsigned_conversion(
			char *str, int width, int precision, va_list(ap));
int			**ptr_flags_infos(char *str);
int			**ptr_format_specifier_infos(
			char *str, int asterisk_width, int asterisk_precision);
char		*set_ptr_result(char *s, int **infos);
char		*format_ptr(char *str, int asterisk_width,
			int precision_width, unsigned long ptr);
int			**pass_width(const char *str, int i);
int			**pass_dot(const char *str, int i);
int			**pass_precision(const char *str, int i, int dot_check);
int			pass_decimal_flags(const char *str);
int			decimal_final(const char *str, int i);
int			examine_decimal(const char *str);
int			pass_unsigned_flags(const char *str);
int			unsigned_final(const char *str, int i);
int			examine_unsigned(const char *str);
int			pass_oct_hex_flags(const char *str);
int			oct_final(const char *str, int i);
int			hex_final(const char *str, int i);
int			examine_oct(const char *str);
int			examine_hex(const char *str);
int			pass_ptr_flags(const char *str);
int			ptr_final(const char *str, int i);
int			examine_ptr(const char *str);
int			pass_str_flags(const char *str);
int			str_final(const char *str, int i);
int			examine_str(const char *str);
int			pass_char_flags(const char *str);
int			char_final(const char *str, int i);
int			examine_char(const char *str);
int			sanity_check(const char *str);
int			specifier_check(char c);
int			str_check(const char *str, char *tmp);
int			*print_character(char *str, int i, int num, va_list ap);
char		*process_null(int **infos);
int			pass_percent_flags(const char *str);
int			examine_percent(const char *str);
int			**percent_flags_infos(char *str);
int			**percent_format_specifier_infos(char *str, int asterisk_width);
char		*set_percent_result(char *s, int **infos);
char		*formatting_percent(char *str, int asterisk_width);
int			**check_width_minus_str(
			char *format, int asterisk_width, int asterisk_precision);
int			**check_minus_width(
			char *str, int asterisk_width, int asterisk_precision);
char		*get_format_specifier(char *str);
int			print_conversioned(char *str, int width, int precision, va_list ap);
int			*print_character(char *str, int i, int num, va_list ap);
int			ft_printf(char *str, ...);
int			percent_final(const char *str, int i);
#endif
