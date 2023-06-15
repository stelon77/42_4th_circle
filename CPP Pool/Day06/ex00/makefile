# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/06 18:25:10 by lcoiffie          #+#    #+#              #
#    Updated: 2021/01/27 17:55:45 by lcoiffie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		convert

COMP =		clang++ $(FLAGS)  -c -o

FLAGS =		-Wall -Werror -Wextra

OBJ_DIR =	obj/

CFILE =		main.cpp \
			Conversion.cpp

CFIND =		$(CFILE:%=$(SRC_DIR)%)

OFILE =		$(CFILE:%.cpp=%.o)

OBJ =		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create:  convert Object directory

$(NAME): $(OBJ)
		@clang++  -o $(NAME) $(addprefix $(OBJ_DIR), $(OFILE)) $(FLAGS)
		@echo convert COMPLETE

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo Create: $(@:obj/%=%)
		@$(COMP) $(OBJ_DIR)$@ $(@:%.o=%.cpp)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@echo Cleaned convert object files

fclean: clean
		@/bin/rm -f $(NAME)
		@echo Cleaned $(NAME)

re: fclean all

.PHONY: all clean fclean re test

