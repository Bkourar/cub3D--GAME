NAME = cub3D

SRCS = main.c trans_rad_deg.c run_game.c move_player.c line.c calcult.c rendring.c map_2.c \
get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
libft/ft_strncmp.c libft/ft_error.c parsing_cub/ft_parsing.c parsing_cub/util1.c parsing_cub/util2.c\
parsing_cub/util3.c parsing_cub/util4.c parsing_cub/util5.c mini_map.c
 
OBJS = $(SRCS:.c=.o)

CFLAGS =  -O3 -ffast-math #-fsanitize=address -g #-Wall -Wextra -Werror 

MLX42 = MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

RM = rm -rf

CC = cc

RED = \033[0;31m
GREEN = \033[0;32m

 			: $(NAME)
$(NAME)			: $(OBJS)
	$(CC) $(MLX42) $(OBJS) -o $(NAME) $(CFLAGS)
	@echo "$(GREEN)make cub"

%.o : %.c recast.h get_next_line/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@ 

fclean : clean
	@$(RM) $(NAME) 
	@echo "$(RED)clean cub"

clean :
	@$(RM) $(OBJS)

re : fclean $(NAME)