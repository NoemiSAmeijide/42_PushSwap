# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 21:00:45 by nosilves          #+#    #+#              #
#    Updated: 2023/10/02 22:24:46 by nosilves         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#--------------------------------COLORS-------------------------------#
BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

#-------------------------------VARIABLES-----------------------------#

NAME = push_swap
INCLUDE = push_swap.h
INC_DIR := inc/
LIB_DIR	:= $(INC_DIR)printf/
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.
I	= -I./$(LIB_DIR)

SRC = control.c push_swap.c

OBJS_S = $(SRC:.c=.o)

#--------------------------IMPLICIT METHODS--------------------------#

$(NAME) : $(OBJ) $(INCLUDE)
	ar rcs $(NAME) $(OBJ)

%.o : %.c $(INCLUDE)
	@printf "${YELLOW}\rCompiling (╮°-°)╮┳━┳ ${GREEN} : $<\n"
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@


#-----------------------------FUNCTIONS-------------------------------#

all: makelib $(NAME) 

makelib:
	@$(MAKE) -C $(LIB_DIR)

$(NAME):: $(OBJS) $(INCLUDE)
	@$(CC) $(CFLAGS) $(OBJS) -L $(LIB_DIR) -lftprintf -o 

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@echo "${RED}Cleaning... (ノಠ益ಠ)ノ彡┻━┻${GRAY}"
	$(RM) $(OBJS) 

fclean: clean
	@echo "Cleaning all!!!🧼"
	@$(MAKE) fclean -C $(LIB_DIR)
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re
