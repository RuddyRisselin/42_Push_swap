# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrisseli <rrisseli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 18:00:43 by rrisseli          #+#    #+#              #
#    Updated: 2024/04/03 13:47:57 by rrisseli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


	#===CONFIGURATION===
NAME = push_swap
NAME_BONUS = checker

SRC			=	main.c \
                error_free.c \
                stack_init.c \
                stack_utils.c \
                tiny_sort.c \
                push_cmd.c \
                swap_cmd.c \
                rev_rotate_cmd.c \
                rotate_cmd.c \
                push_swap.c \
                push_swap_init.c \
                split.c \
				opti_algo.c \

SRC_BONUS	=	checker.c \
                checker_utils.c \
                error_free.c \
                stack_init.c \
                stack_utils.c \
                tiny_sort.c \
                push_cmd.c \
                swap_cmd.c \
                rev_rotate_cmd.c \
                rotate_cmd.c \
                push_swap.c \
                push_swap_init.c \
                split.c \
				opti_algo.c \

CFLAGS = -Wall -Werror -Wextra

LIBS = \
	libft/libft.a\

INCLUDES = -Ilibft/

OBJ_DIR = obj

#===AUTOMATIC VARS===

OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC_BONUS)))))

LIB_FLAGS = $(addprefix -L, $(dir $(LIBS))) $(addprefix -l, $(patsubst lib%.a, %, $(notdir $(LIBS))))

#===TARGETS===
all : $(NAME)

bonus : $(NAME_BONUS)

#===COMPILING===
$(OBJ_DIR) :
	$(shell mkdir -p $(OBJ_DIR))
$(OBJ_DIR)/%.o : %.c
	cc $(CFLAGS) -o $@ -c $< $(INCLUDES)
$(OBJ_DIR)/%_bonus.o : bonus/%.c
	cc $(CFLAGS) -o $@ -c $< $(INCLUDES)
%.a :
	make -C $(dir $@)

#===LINKING===
$(NAME_BONUS) : $(OBJ_DIR) $(LIBS) $(OBJ_BONUS)
	cc -o $(NAME_BONUS) $(OBJ_BONUS) $(LIB_FLAGS)
$(NAME) : $(OBJ_DIR) $(LIBS) $(OBJ)
	cc -o $(NAME) $(OBJ) $(LIB_FLAGS)

#===CLEAN===
clean :
	rm -rf $(OBJ_DIR) || true

#===FCLEAN===
fclean : clean
	rm -f $(NAME) $(NAME_BONUS) libft/*.o  libft/*.a|| true

#===RE===
re : fclean all


.PHONY : re fclean clean all default bonus