# Program
NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I include
AR = ar -crs
RM = rm -rf
O = obj/
SRC = src/ft_printf.c \
	  src/utils/utils.c \
	  src/utils/formatting.c \
	  src/utils/base_formatting.c \
	  src/conversions/printchar.c \
	  src/conversions/printstr.c \
	  src/conversions/printnum.c \
	  src/conversions/printbase.c \
	  src/conversions/printptr.c
OBJ = $(SRC:%=$O%.o)
UNW = .DS_Store ./*/.DS_Store

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Custom
BONUS = 0

all: $(NAME)

bonus: BONUS := 1
bonus: $(NAME)

$(NAME): precomp $(OBJ)
	@echo "$(GREEN)Objects compiled successfully$(DEF_COLOR)\n"
	@make -C libft
	@cp libft/libft.a $(NAME)
	@echo "$(YELLOW)Generating library archive$(DEF_COLOR)\n"
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) compiled successfully$(DEF_COLOR)\n"

$O%.o: %
	$(CC) $(CFLAGS) -DBONUS=$(BONUS) $(INCLUDE) -c $^ -o $@

precomp:
	@echo "$(YELLOW)Creating object directories.$(DEF_COLOR)\n"
	@mkdir -p $O/src/conversions
	@mkdir -p $O/src/utils
	@echo "$(YELLOW)Compiling $(NAME) objects.$(DEF_COLOR)\n"

clean:
	@echo "$(GREEN)Cleaning compiled $(NAME) sources.$(DEF_COLOR)\n"
	@make clean -C libft
	@$(RM) $O

fclean: clean
	@make fclean -C libft
	@$(RM) $(NAME)

xclean: fclean
	@make xclean -C libft
	@$(RM) $(UNW)

re: fclean all

bre: fclean bonus

debug: re xclean
	$(RM) $O $(NAME); norminette

bdebug: bre xclean
	$(RM) $O $(NAME); norminette

cdebug: debug
	sleep 4; clear

cbdebug: bdebug
	sleep 4; clear

.PHONY: all bonus clean fclean xclean re
