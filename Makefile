# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 18:15:12 by pschemit          #+#    #+#              #
#    Updated: 2022/06/08 12:39:16 by pschemit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR			:=	src/
OBJ_DIR			:=	obj/
#BIN_DIR			:=	bin/

SRC				:=	main.c		exception.c	ft_split.c	ft_strjoin.c		operation.c parsing.c sorting.c parcing_2.c
SRC_PATH		:=	$(addprefix $(SRC_DIR), $(SRC))

OBJ				:=	${SRC_PATH:.c=.o}
OBJ_PATH		:=	$(subst $(SRC_DIR),$(OBJ_DIR), $(OBJ))

NAME			:=	push_swap
#NAME_PATH		:=	$(addprefix $(BIN_DIR), $(NAME))

CC				:=	gcc
CFLAGS			:=	-Wall -Wextra -Werror
LFLAGS			:=	

$(OBJ_DIR)%.o	: $(SRC_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -c $< -o ${addprefix $(OBJ_DIR), ${<:$(SRC_DIR)%.c=%.o}}

${NAME}	: ${OBJ_PATH}
#				@mkdir -p $(BIN_DIR)
				@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ_PATH) -o $(NAME)

all				: $(NAME)

clean			:
				@rm -rf $(OBJ_DIR)
				@rm -rf ${NAME}

fclean			: clean
				@rm -rf $(OBJ_DIR)
				@rm -rf ${NAME}

re				: fclean all

.PHONY			: all clean fclean re