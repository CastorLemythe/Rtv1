# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/14 13:29:39 by kehuang           #+#    #+#              #
#    Updated: 2018/07/19 11:48:25 by kehuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=			libft.a

#==============================================================================#
#------------------------------------------------------------------------------#
#                               DIRECTORIES                                    #

SRC_DIR			:=			srcs
INC_DIR			:=			./includes
OBJ_DIR			:=			./objs

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  FILES                                       #

SRC_NAME		:=			ft_atoi.c				\
							ft_bzero.c				\
							ft_free_str2.c			\
							ft_isalnum.c			\
							ft_isalpha.c			\
							ft_isascii.c			\
							ft_isdigit.c			\
							ft_isprint.c			\
							ft_iswhitespace.c		\
							ft_itoa.c				\
							ft_itoa_base.c			\
							ft_memalloc.c			\
							ft_memccpy.c			\
							ft_memchr.c				\
							ft_memcmp.c				\
							ft_memcpy.c				\
							ft_memdel.c				\
							ft_memmove.c			\
							ft_memset.c				\
							ft_putchar.c			\
							ft_putchar_fd.c			\
							ft_putendl.c			\
							ft_putendl_fd.c			\
							ft_putnbr.c				\
							ft_putnbr_fd.c			\
							ft_putstr.c				\
							ft_putstr_fd.c			\
							ft_putunbr_fd.c			\
							ft_str2len.c			\
							ft_strcat.c				\
							ft_strchr.c				\
							ft_strclen.c			\
							ft_strclr.c				\
							ft_strcmp.c				\
							ft_strcpy.c				\
							ft_strdel.c				\
							ft_strdup.c				\
							ft_strequ.c				\
							ft_striter.c			\
							ft_striteri.c			\
							ft_strjoin.c			\
							ft_strlcat.c			\
							ft_strlen.c				\
							ft_strmap.c				\
							ft_strmapi.c			\
							ft_strncat.c			\
							ft_strncmp.c			\
							ft_strncpy.c			\
							ft_strndup.c			\
							ft_strnequ.c			\
							ft_strnew.c				\
							ft_strnlen.c			\
							ft_strnstr.c			\
							ft_strrchr.c			\
							ft_strsplit.c			\
							ft_strstr.c				\
							ft_strsub.c				\
							ft_strtrim.c			\
							ft_swap.c				\
							ft_tolower.c			\
							ft_toupper.c			\
							get_next_line.c			\

SRC_ALL			:= 			$(addprefix $(SRC_DIR)/,$(SRC_NAME:.c=.o))

OBJ				:=			$(addprefix $(OBJ_DIR)/,$(SRC_NAME:.c=.o))
NB				:=			$(words $(SRC_ALL))
INDEX			:=			0

#==============================================================================#
#------------------------------------------------------------------------------#
#                            COMPILER & FLAGS                                  #

CC				:=			gcc
CFLAGS			:=			-Wall -Wextra -Werror -I$(INC_DIR)

#==============================================================================#
#------------------------------------------------------------------------------#
#                                 RULES                                        #

all:					$(NAME)

$(NAME):				$(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "[ 100%% ] %s                                                       \n" "libft.a"

$(OBJ_DIR)/%.o:			$(SRC_DIR)/%.c $(INC_DIR)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval TO_DO=$(shell echo "$@"))
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[ %d%% ] %s :: %s        \r" $(PERCENT) $(NAME) $@
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Clean of $(NAME) is done ---"

fclean: 				clean
	@rm -rf $(NAME)
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Fclean of $(NAME) is done ---"

re:
	@$(MAKE) fclean
	@$(MAKE)

.PHONY: all clean fclean re build cbuild
