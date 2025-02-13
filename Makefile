NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf_utils.c \
	ft_printf_utils2.c   \
	ft_printf.c

OBJS = $(SRCS:.c=.o)

# Par défaut, on compile sans les bonus
all: $(NAME)

# Compilation de la bibliothèque sans les bonus
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compilation des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Suppression des fichiers objets
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

# Suppression complète
fclean: clean
	rm -f $(NAME)

# Reconstruction complète
re: fclean all
