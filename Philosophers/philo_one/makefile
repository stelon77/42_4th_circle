# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/15 18:39:00 by lcoiffie          #+#    #+#              #
#    Updated: 2021/03/22 14:56:28 by lcoiffie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =		philo_one

COMP =		clang $(FLAGS) $(PHILO_ONE_H) -c -o

FLAGS =		-Wall -Werror -Wextra

PHILO_ONE_H =	-I includes/

OBJ_DIR =	obj/

SRC_DIR =	srcs/

CFILE =		main.c \
			ft_lib.c \
			check_error.c \
			time.c \
			initialization.c \
			put_text.c \
			destroy.c \
			thread.c \
			algo_fork.c

CFIND =		$(CFILE:%=$(SRC_DIR)%)

OFILE =		$(CFILE:%.c=%.o)

OBJ =		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: Philo_one Object directory

$(NAME): $(OBJ)
		@clang  -o $(NAME) $(addprefix $(OBJ_DIR), $(OFILE)) $(FLAGS) -lpthread
		@echo PHILO_ONE COMPLETE

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo Create: $(@:obj/%=%)
		@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@echo Cleaned Philo_one object files

fclean: clean
		@/bin/rm -f $(NAME)
		@echo cleaned totally $(NAME)

re: fclean all

.PHONY: all clean fclean re
