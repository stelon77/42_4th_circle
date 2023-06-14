# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/06 18:25:10 by lcoiffie          #+#    #+#              #
#    Updated: 2020/12/05 02:10:09 by lcoiffie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		megaphone

COMP =		clang++ $(FLAGS)  -c -o

FLAGS =		-Wall -Werror -Wextra

OBJ_DIR =	obj/

CFILE =		megaphone.cpp

CFIND =		$(CFILE:%=$(SRC_DIR)%)

OFILE =		$(CFILE:%.cpp=%.o)

OBJ =		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: megaphone Object directory

$(NAME): $(OBJ)
		@clang++  -o $(NAME) $(addprefix $(OBJ_DIR), $(OFILE)) $(FLAGS)
		@echo megaphone COMPLETE

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo Create: $(@:obj/%=%)
		@$(COMP) $(OBJ_DIR)$@ $(@:%.o=%.cpp)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@echo Cleaned megaphone object files

fclean: clean
		@/bin/rm -f $(NAME)
		@echo Cleaned $(NAME)

re: fclean all

test:	$(OBJ_DIR) $(NAME)
			./megaphone "shhhhh... I think the students are asleep..."
			./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
			./megaphone

.PHONY: all clean fclean re test

