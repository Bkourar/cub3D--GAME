NAME = cub3d
NAMEB = cub3d_bonus

# Source files for bonus
BSRCP = Bonus/Parse/get_next_line/get_next_line.c Bonus/Parse/get_next_line/get_next_line_utils.c \
		Bonus/Parse/libft/ft_strncmp.c Bonus/Parse/libft/ft_error.c \
		Bonus/Parse/parsing_cub/ft_parsing.c Bonus/Parse/parsing_cub/util1.c Bonus/Parse/parsing_cub/util2.c\
		Bonus/Parse/parsing_cub/util3.c Bonus/Parse/parsing_cub/util4.c Bonus/Parse/parsing_cub/util5.c

BSRCR = Bonus/Raycast/Raycasting.c Bonus/Raycast/checker.c Bonus/Raycast/math_formulas.c Bonus/Raycast/randering.c \
		Bonus/Raycast/run_game.c Bonus/Raycast/setter_for_data.c Bonus/Raycast/moves.c

# Source files for mandatory
MSRCP = Mandatory/Parse/get_next_line/get_next_line.c Mandatory/Parse/get_next_line/get_next_line_utils.c \
		Mandatory/Parse/libft/ft_strncmp.c Mandatory/Parse/libft/ft_error.c \
		Mandatory/Parse/parsing_cub/ft_parsing.c Mandatory/Parse/parsing_cub/util1.c Mandatory/Parse/parsing_cub/util2.c\
		Mandatory/Parse/parsing_cub/util3.c Mandatory/Parse/parsing_cub/util4.c Mandatory/Parse/parsing_cub/util5.c

MSRCR = Mandatory/Raycast/Raycasting.c Mandatory/Raycast/checker.c Mandatory/Raycast/math_formulas.c Mandatory/Raycast/randering.c \
		Mandatory/Raycast/run_game.c Mandatory/Raycast/setter_for_data.c Mandatory/Raycast/moves.c

# Object file lists for mandatory and bonus
SRCSM = $(MSRCP) $(MSRCR) Mandatory/main.c
OBJSM = $(SRCSM:.c=.o)

SRCSB = $(BSRCP) $(BSRCR) main_bonus.c
OBJSB = $(SRCSB:.c=.o)

# Compiler settings
CFLAGS = -Wall -Wextra -Werror -O3

MLX42 = MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

RM = rm -rf
CC = cc

# Colors for terminal output
RED = \033[0;31m
GREEN = \033[0;32m

# Targets
all: $(NAME)

# Compile mandatory version
$(NAME): $(OBJSM)
	$(CC) $(MLX42) $(OBJSM) -o $(NAME)
	@echo "$(GREEN)make cub3d_mandatory"

# Compile bonus version
$(NAMEB): $(OBJSB)
	$(CC) $(MLX42) $(OBJSB) -o $(NAMEB)
	@echo "$(GREEN)make cub3d_bonus"

# Compilation rule for mandatory object files
Mandatory/%.o: Mandatory/%.c Mandatory/Includs/raycast.h Mandatory/Parse/get_next_line/get_next_line.h Mandatory/Includs/parse.h
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN) Compiling $@"

# Compilation rule for bonus object files
Bonus/%.o: Bonus/%.c Bonus/Includs/raycast_bonus.h Bonus/Parse/get_next_line/get_next_line.h Bonus/Includs/parse_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN) Compiling $@"

# Clean up object files and binaries
clean:
	@$(RM) $(OBJSM) $(OBJSB)
	@echo "$(RED) Cleaned object files"

# Full clean and recompile
fclean: clean
	@$(RM) $(NAME) $(NAMEB)
	@echo "$(RED) Cleaned binaries"

# Rebuild everything
re: fclean all
