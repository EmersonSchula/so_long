
# COLORS
GREEN := \033[32m
RED := \033[31m
CYAN := \033[36m
VIOLET := \033[38;5;208m
COLOR_LIMITER := \033[0m


# NAME
NAME := so_long


# FLAGS
CFLAGS := -Ofast -fno-stack-protector -ffast-math -Wall -Wextra -Wunreachable-code -g3 -Werror
LIBS := -ldl -lglfw -pthread -lm


# LIBS
LIB_PATH := ./libs/libft
LIB_NAME := libft.a
MLX_PATH := ./libs/MLX42
MLX_BUILD_PATH := $(MLX_PATH)/build
MLX_NAME := libmlx42.a


# PATHS
SRC_PATH := ./src/
BIN_PATH := ./bin/
HEADER_PATH := ./includes/


# SOURCES AND OBJECTS
FILES := \
	validation.c \
	image.c \
	error.c \
	utils.c \
	hook.c \
	init.c \
	map.c \
	mlx.c \
	main.c
SRCS := $(addprefix $(SRC_PATH), $(FILES))
OBJS := $(addprefix $(BIN_PATH), $(FILES:%.c=%.o))


all: mlx libft $(BIN_PATH) print $(NAME)


mlx: 
ifeq ($(wildcard $(MLX_BUILD_PATH)/$(MLX_NAME)),)
	@printf "$(CYAN)-------------------- --------------- --------------------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)--------------------| COMPILING MLX |--------------------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)-------------------- --------------- --------------------$(COLOR_LIMITER)\n"
	@cmake $(MLX_PATH) -B $(MLX_BUILD_PATH)
	@make -C $(MLX_BUILD_PATH) -j4 --no-print-directory
endif


libft:
ifeq ($(wildcard $(LIB_PATH)/$(LIB_NAME)),)
	@printf "$(CYAN)------------------- ----------------- -------------------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)-------------------| COMPILING LIBFT |-------------------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)------------------- ----------------- -------------------$(COLOR_LIMITER)\n"
	@make build -C $(LIB_PATH) --no-print-directory
endif


$(BIN_PATH):
	@mkdir -p $(BIN_PATH)


print:
ifeq ($(wildcard $(NAME)),)
	@printf "$(GREEN) ------------------------$(COLOR_LIMITER)"
	@printf "$(GREEN)| Compiling Main Project |$(COLOR_LIMITER)"
	@printf "$(GREEN)------------------------$(COLOR_LIMITER)"
	@echo " "
endif


$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_PATH)/$(LIB_NAME) $(MLX_BUILD_PATH)/$(MLX_NAME) $(LIBS) -I$(HEADER_PATH)
	@printf "$(CYAN)------ ----------------------------------------------- ------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)------| SO_LONG executable was created successfully!! |------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)------ ----------------------------------------------- ------$(COLOR_LIMITER)\n"
	@echo " "


$(BIN_PATH)%.o: $(SRC_PATH)%.c
	@printf "$(GREEN)[Compiling]$(COLOR_LIMITER) $(notdir $<)..."
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER_PATH)
	@echo " "

norm:
	@echo "\n$(BLUE)======= INCLUDES =======$(END)"
	@norminette includes | sed 's/OK/\x1b[1;32m&\x1b[0m/g' | sed 's/Error/\x1b[1;31m&\x1b[0m/g'
	@echo "\n$(MAGENTA)======= SRC =======$(END)"
	@norminette src | sed 's/OK/\x1b[1;32m&\x1b[0m/g' | sed 's/Error/\x1b[1;31m&\x1b[0m/g'
	@echo "\n$(MAGENTA)======= LIBFT =======$(END)"
	@norminette libs/libft | sed 's/OK/\x1b[1;32m&\x1b[0m/g' | sed 's/Error/\x1b[1;31m&\x1b[0m/g'


clean:
	@printf "$(RED)[Removing Objects...]$(COLOR_LIMITER)\n"
	@make fclean -C $(LIB_PATH) --no-print-directory
	@rm -rf $(MLX_BUILD_PATH)
	@rm -rf $(BIN_PATH)
	@rm -rf $(VALGRIND_LOG)


fclean: clean
	@printf "$(RED)[Removing $(notdir $(NAME))...]$(COLOR_LIMITER)\n"
	@rm -rf $(NAME)
	@rm -rf $(BONUS_NAME)


re: fclean
	@make --no-print-directory


.PHONY: all clean fclean re print libft mlx print_bonus valgrind_bonus