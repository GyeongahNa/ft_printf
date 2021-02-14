NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = align.c asterisk_check.c character_formatting.c decimal_flag_infos.c \
	  decimal_formatting.c examine_char.c examine_decimal.c examine_hex_oct.c \
	  examine_ptr.c examine_str.c examine_unsigned.c ft_atoi.c ft_find_chr.c \
	  ft_find_str.c ft_last_chr.c ft_printf.c ft_putchar.c ft_putstr.c ft_strcat.c \
	  ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_substr.c \
	  ft_toupper.c hex_for_unsigned_longlong.c hexadecimal_flag_infos.c \
	  hexadecimal_formatting.c itoa_for_longlong.c itoa_for_unsigned_longlong.c \
	  manage_double_ptr.c numeric_conversion.c octal_flag_infos.c octal_for_unsigned_longlong.c \
	  octal_formatting.c pass_width_precision.c pointer_formatting.c sanity_check.c string_flag_infos.c \
	  string_formatting.c unsigned_int_flag_infos.c unsigned_int_formatting.c width_and_precision_infos.c \
	  hexadecimal_formatting2.c numeric_conversion2.c examine_percent.c percent_formatting.c percent_flag_infos.c
	  
OBJ = $(subst .c,.o,$(SRC))


all : $(NAME)

$(NAME):
		$(CC) $(CFLAGS) -c $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean :
		/bin/rm -f $(OBJ)

fclean : clean
		/bin/rm -f $(NAME)

re : fclean all

.PHONY : clean fclean all re
