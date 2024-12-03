# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 12:25:55 by carzhang          #+#    #+#              #
#    Updated: 2024/10/11 16:43:59 by carzhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_realloc.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c Ft_printf/ft_printd.c Ft_printf/ft_printf.c Ft_printf/ft_printp.c Ft_printf/ft_print_unsigned.c Ft_printf/ft_printuppercase.c Ft_printf/ft_printx.c Ft_printf/ft_putchar.c Ft_printf/ft_putstr.c Ft_printf/ft_itoabase.c Get_next_line/get_next_line.c Get_next_line/get_next_line_utils.c Get_next_line/get_next_line_bonus.c Get_next_line/get_next_line_utils_bonus.c

INCLUDES = libft.h Ft_printf/ft_printf.h Get_next_line/get_next_line.h Get_next_line/get_next_line_bonus.h

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror $(addprefix -I, $(dir $(INCLUDES)))

all: $(NAME)

$(NAME): $(OBJS)
		@echo "Building objects"
		@ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
