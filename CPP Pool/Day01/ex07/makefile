# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/06 18:25:10 by lcoiffie          #+#    #+#              #
#    Updated: 2021/01/04 11:34:05 by lcoiffie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		replace

COMP =		clang++ $(FLAGS)  -c -o

FLAGS =		-Wall -Werror -Wextra -std=c++98

OBJ_DIR =	obj/

CFILE =		main.cpp \
			Sed.cpp

CFIND =		$(CFILE:%=$(SRC_DIR)%)

OFILE =		$(CFILE:%.cpp=%.o)

OBJ =		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create:  replace Object directory

$(NAME): $(OBJ)
		@clang++  -o $(NAME) $(addprefix $(OBJ_DIR), $(OFILE)) $(FLAGS)
		@echo replace COMPLETE

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo Create: $(@:obj/%=%)
		@$(COMP) $(OBJ_DIR)$@ $(@:%.o=%.cpp)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@echo Cleaned replace object files

fclean: clean
		@/bin/rm -f $(NAME)
		@echo Cleaned $(NAME)

re: fclean all

.PHONY: all clean fclean re

