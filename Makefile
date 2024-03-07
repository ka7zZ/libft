# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 13:11:03 by aghergut          #+#    #+#              #
#    Updated: 2024/03/07 15:50:14 by aghergut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = libft.a
MAIN = run

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
       ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
       ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
       ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
       ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
       ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
       ft_putnbr_fd.c ft_atoi.c	\
	   ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	   ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	   ft_lstiter.c ft_lstmap.c main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME) $(MAIN)
	
$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

$(MAIN): $(OBJS)
	@$(CC) $(CFLAGS) -o $(MAIN) main.c -L. -lft
 
%.o: %.c
	@mkdir -p $(dir (OBJS))
	@echo "Compiling $< ..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\tSuccessfully Added $<\n"

clean: 
	rm -Rf $(OBJS)	

fclean: clean
	rm -f $(NAME) $(MAIN)

re: fclean all

.PHONY: all clean fclean re
