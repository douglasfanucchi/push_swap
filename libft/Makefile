# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/17 17:17:55 by gucoelho          #+#    #+#              #
#    Updated: 2026/06/16 15:51:56 by dode-lim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs

INCLUDES	= includes

FT_PRINTF_DIR	:= ft_printf
FT_PRINTF_FILES	:= ft_printf_bonus.c\
				   ft_printf_utils_bonus.c\
				   specs_setup_bonus.c\
				   ft_convert_integer_bonus.c\
				   ft_convert_char_and_str_bonus.c\
				   ft_convert_pointer_bonus.c\
				   ft_convert_base_bonus.c\
				   ft_convert_float.c\
				   precision_bonus.c\
				   width_bonus.c
FT_PRINTF_SRC	:= $(addprefix $(FT_PRINTF_DIR)/,$(FT_PRINTF_FILES))

SRCS        = ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isspace.c \
			ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_atoi.c ft_atol.c ft_strdup.c \
			ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_utoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
			ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
			$(FT_PRINTF_SRC)

OBJS        = $(SRCS:.c=.o)

all: $(FT_PRINTF) $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re






















