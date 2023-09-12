#SRC_DIR = src
#
#SRCS = ft_validate_map.c ft_validate_2dmap.c main.c ft_validate_path.c ft_utils.c
#
#OBJ_DIR = obj
#
#OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
#
#CC = cc
#RM = rm -f
#CFLAGS = -Wall -Wextra -Werror -I.
#
#LIB_DIR = libft
#
#all: $(NAME)
#
#$(LIB_DIR)/libft.a:
#	@$(MAKE) -C $(LIB_DIR)
#
#NAME = so_long.a
#
#$(NAME): $(LIB_DIR)/libft.a $(OBJS)
#	ar rcs $(NAME) $(OBJS)
#
#$(OBJS): | $(OBJ_DIR)
#
#$(OBJ_DIR):
#	mkdir -p $(OBJ_DIR)
#
#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
#	@$(CC) $(CFLAGS) -c -o $@ $<
#
#clean:
#	@$(RM) $(OBJS)
#	@$(MAKE) -C $(LIB_DIR) clean
#
#fclean: clean
#	$(RM) $(NAME)
#	@$(MAKE) -C $(LIB_DIR) fclean
#
#re: fclean all
#
#.PHONY: all clean fclean re

NAME        := so_long
CFLAGS      := -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX      := ./MLX42
LIBFT       := ./libft
HEADERS     := -I ./include -I $(LIBMLX)/include/MLX42 -I $(LIBFT)/include
LIBS        := $(LIBFT)/libft.a
SRCS        := $(shell find ./src -iname "*.c")
OBJS        := ${SRCS:.c=.o}
all: lib $(NAME)
lib:
		@$(MAKE) -C $(LIBFT)
		 @if [ ! -d "$(LIBMLX)" ]; then \
				git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); \
		fi
		@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
%.o: %.c
		@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<) "
$(NAME): $(OBJS)
		@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
clean:
		@rm -f $(OBJS)
		@$(MAKE) clean -C $(LIBFT)
fclean: clean        
		@rm -fr $(LIBMLX)
		@rm -f $(NAME)
		@$(MAKE) fclean -C $(LIBFT)
re: clean all
.PHONY: all, clean, fclean, re, lib