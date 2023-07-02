CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -crs
O = obj/
SRC = ft_toupper.c \
	  ft_tolower.c \
	  ft_isalpha.c \
	  ft_isupper.c \
	  ft_islower.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strlen.c \
	  ft_strncmp.c \
	  ft_memset.c \
	  ft_memchr.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memcmp.c \
	  ft_memmove.c \
	  ft_strlcpy.c \
	  ft_strlcat.c \
	  ft_append.c \
	  ft_preppend.c \
	  ft_strnstr.c \
	  ft_atoi.c \
	  ft_calloc.c \
	  ft_strdup.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_split.c \
	  ft_itoa.c \
	  ft_ltoa.c \
	  ft_strmapi.c \
	  ft_striteri.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putsubstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \

BSRC = ft_lstnew.c \
	   ft_lstadd_front.c \
	   ft_lstsize.c \
	   ft_lstlast.c \
	   ft_lstadd_back.c \
	   ft_lstdelone.c \
	   ft_lstclear.c \
	   ft_lstiter.c \
	   ft_lstmap.c

OBJ = $(SRC:%=$O%.o)
BOBJ = $(BSRC:%=$O%.o)
NAME = libft.a
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

all: mkdir $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) compiled successfully.$(DEF_COLOR)\n"

bonus: mkdir $(BOBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(BOBJ)
	@echo "$(GREEN)$(NAME) bonus compiled successfully.$(DEF_COLOR)\n"

$(NAME): re

$O%.o: %
	$(CC) $(CFLAGS) -c $^ -o $@ -g

mkdir:
	mkdir -p $O

clean:
	rm -rf $O

fclean: clean
	rm -rf $(NAME)

xclean: fclean
	rm -rf $(UNW)

re: fclean all

bre: fclean bonus

debug: re xclean
	rm -rf $O; rm -rf $(NAME); norminette

bdebug: bre xclean
	rm -rf $O; rm -rf $(NAME); norminette

cdebug: debug
	sleep 4; clear

cbdebug: bdebug
	sleep 4; clear

.PHONY: all clean fclean xclean re
