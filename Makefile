NAME	= pipex

SRCS	= ./srcs/child_processes.c ./srcs/execute_cmd.c ./srcs/get_path.c \
	  ./srcs/pipex.c ./srcs/utils.c
SRCS_BONUS	= ./srcs_bonus/execute_command.c ./srcs_bonus/get_path.c \
		  ./srcs_bonus/pipex_bonus.c ./srcs_bonus/print_heredoc.c \
		  ./srcs_bonus/redirection.c ./srcs_bonus/utils_bonus.c

OBJS	= $(patsubst %.c,%.o,$(SRCS))
OBJS_BONUS	= $(patsubst %.c,%.o,$(SRCS_BONUS))

D_FILES	= $(patsubst %.c,%.d,$(SRCS) $(SRCS_BONUS))

LIB_DIR		= ./libft

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $? $(LIB_DIR)/libft.a -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -MD

bonus: $(OBJS_BONUS)
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $? $(LIB_DIR)/libft.a -o $(NAME)

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS) $(D_FILES)
	@make clean -C $(LIB_DIR)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB_DIR)

-include $(D_FILES)

re: fclean all

.PHONY: all clean fclean re bonus
