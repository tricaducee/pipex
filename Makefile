ECHO = @echo
PRINT = @printf
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
INVERT = \033[7m
RESETTXT = \033[0m
BOLD = \033[1m

RM = rm -rf

SRC = $(wildcard *.c libft/*.c free_and_secure/*.c)

OBJ = $(SRC:.c=.o)

NAME = pipex

CC = gcc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

$(NAME) : $(OBJ)
	@make -C printfd
	$(ECHO) "$(YELLOW)Compilation de pipex...$(RESETTXT)"
	@$(CC) $(CFLAGS) -o $@ printfd/libftprintfd.a $^
	$(ECHO) "$(GREEN)$(BOLD)Compilation Terminée !!!$(RESETTXT)"

%.o : %.c
	$(PRINT) "$(YELLOW)Generation des objets...$(RESETTXT)\r"
	@$(CC) $(CFLAGS) -o $@ -c $<

bonus : $(NAME)

all : $(NAME)

clean :
	@make clean -C printfd 
	$(ECHO) "$(RED)Suppression des objets...$(RESETTXT)"
	@$(RM) $(OBJ)
	$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

fclean : clean
	@$(RM) printfd/libftprintfd.a
	$(ECHO) "$(RED)Suppression de pipex et libftprintfd.a...$(RESETTXT)"
	@$(RM) $(NAME)
	$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

re : fclean all

.PHONY: all re bonus clean fclean