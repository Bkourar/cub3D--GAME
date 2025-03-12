NAME = cub3D

# SRCS = main.c trans_rad_deg.c run_game.c move_player.c line.c calcult.c rendring.c map_2.c \
# get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
# libft/ft_strncmp.c libft/ft_error.c parsing_cub/ft_parsing.c parsing_cub/util1.c parsing_cub/util2.c\
# parsing_cub/util3.c parsing_cub/util4.c parsing_cub/util5.c

SRCP = Parse/get_next_line/get_next_line.c Parse/get_next_line/get_next_line_utils.c \
		Parse/libft/ft_strncmp.c Parse/libft/ft_error.c \
		Parse/parsing_cub/ft_parsing.c Parse/parsing_cub/util1.c Parse/parsing_cub/util2.c\
		Parse/parsing_cub/util3.c Parse/parsing_cub/util4.c Parse/parsing_cub/util5.c

SRCR = Raycast/Raycasting.c Raycast/checker.c Raycast/math_formulas.c Raycast/randering.c \
		Raycast/run_game.c Raycast/setter_for_data.c Raycast/moves.c

SRCS = $(SRCP) $(SRCR) main.c

# OBJP = $(SRCP:.c=.o)
# OBJP = $(SRCR:.c=.o)

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -o3

MLX42 = MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

RM = rm -rf

CC = cc

RED = \033[0;31m
GREEN = \033[0;32m

all 			: $(NAME)
$(NAME)			: $(OBJS)
	$(CC) $(MLX42) $(OBJS) -o $(NAME) -g -fsanitize=address
	@echo "$(GREEN)make cub"

%.o : %.c Includs/raycast.h Parse/get_next_line/get_next_line.h Includs/parse.h
	$(CC) $(CFLAGS) -c $< -o $@

fclean : clean
	@$(RM) $(NAME) 
	@echo "$(RED)clean cub"

clean :
	@$(RM) $(OBJS)

re : fclean $(NAME)