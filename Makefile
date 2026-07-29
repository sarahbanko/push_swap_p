NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Diretorios e Libft
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

# Diretorios de Include (-I para encontrar os .h automaticamente)
INCLUDES    = -I. \
              -I$(LIBFT_DIR) \
              -Ialgorithms \
              -Ioperations \
              -Iparsing \
              -Istack

# Fontes do projeto
SRCS        = main.c \
              algorithms/disorder.c \
              algorithms/simple.c \
              operations/push.c \
              operations/rev_rotate.c \
              operations/rotate.c \
              operations/swap.c \
              parsing/parsing.c \
              stack/stack.c \
              stack/stack_debug.c \
              stack/stack_init.c \
              stack/stack_pop.c \
              stack/stack_push.c \
              stack/stack_utils.c

# Converte a lista de .c para .o
OBJS        = $(SRCS:.c=.o)

# Regra principal
all: $(LIBFT) $(NAME)

# Compila a Libft invocado o Makefile dela
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compila o executavel conectando os objetos e a libft.a
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Regra de compilacao de cada .c para .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Limpeza de arquivos objeto (.o)
clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

# Limpeza completa (objetos + executavel + libft.a)
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# Recompilacao do zero
re: fclean all

.PHONY: all clean fclean re