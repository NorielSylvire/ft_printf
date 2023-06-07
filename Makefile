NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I
INCLUDE = include
AR = ar -crs
RM = rm -rf
O = obj/
SRC = src/ft_printf.c \
	  src/conversions/printchar.c \
	  src/conversions/printstr.c \
	  src/conversions/printnum.c
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

all: $(NAME)

$(NAME): mkdir $(OBJ)
	@make -C libft
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) compiled successfully$(DEF_COLOR)"

bonus: all

$O%.o: %
	$(CC) $(CFLAGS) include -c $^ -o $@

mkdir:
	mkdir -p $O/src/conversions

clean:
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

.PHONY: all clean fclean xclean re
