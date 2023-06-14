# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/06 18:25:10 by lcoiffie          #+#    #+#              #
#    Updated: 2020/12/26 23:12:43 by lcoiffie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ph0neb00k

COMP =		clang++ $(FLAGS)  -c -o

FLAGS =		-Wall -Werror -Wextra

OBJ_DIR =	obj/

CFILE =		main.cpp \
			ClassContact.cpp

CFIND =		$(CFILE:%=$(SRC_DIR)%)

OFILE =		$(CFILE:%.cpp=%.o)

OBJ =		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create:  Ph0neb00k Object directory

$(NAME): $(OBJ)
		@clang++  -o $(NAME) $(addprefix $(OBJ_DIR), $(OFILE)) $(FLAGS)
		@echo ph0neb00k COMPLETE

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo Create: $(@:obj/%=%)
		@$(COMP) $(OBJ_DIR)$@ $(@:%.o=%.cpp)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@echo Cleaned ph0neb00k object files

fclean: clean
		@/bin/rm -f $(NAME)
		@echo Cleaned $(NAME)

re: fclean all

test:	$(OBJ_DIR) $(NAME)
			./ph0neb00k

.PHONY: all clean fclean re test

