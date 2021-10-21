# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skelly <skelly@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 14:11:19 by skelly            #+#    #+#              #
#    Updated: 2021/10/22 02:36:30 by skelly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
NAME_B		= fractol_bonus
HEADER		= fractol.h

SRCS		= fractol.c\
		  	  fractol_init.c\
			  fractol_color.c\
			  fractol_formula.c\
			  fractol_key.c
				
LIBFT		= libft
CC			= gcc -Wall -Wextra -Werror -O3 -fsanitize=address -g
LIB_FLAGS 	= -L libft -lft
RM			= rm -f

all: 		$(NAME)

$(NAME):	$(SRCS) $(HEADER) $(LIBFT)
			@make -s -C $(LIBFT)
			@$(CC) $(LIB_FLAGS) $(SRCS) -L minilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus:		$(SRCS) $(HEADER) $(LIBFT)
			@make -s -C $(LIBFT)
			@$(CC) $(LIB_FLAGS) $(SRCS) -L minilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)	  
		  
clean:
			@make fclean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME) $(NAME_B)

re:			fclean all

norm:		@norminette . | grep Error

.PHONY: all clean fclean re norm
					