NAME = libasm.a

ASM = nasm
ASM_FLAGS = -f elf64

SRC_FILES = ft_read.s ft_write.s ft_strlen.s ft_strcmp.s ft_strcpy.s ft_strdup.s

OBJS = $(SRC_FILES:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	@$(MSG_OK_LIB)

%.o: %.s
	$(ASM) $(ASM_FLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	@$(MSG_OK_CLR)

re: fclean all

.PHONY: all clean fclean re

# --- Messages ----------------------------------------------------

MSG_OK_LIB = echo "$(BOLD_YELLOW)libasm library created$(DEF_COLOR)"
MSG_OK_CLR = echo "$(BOLD_YELLOW)libasm library removed$(DEF_COLOR)"

# --- Colors -------------------------------------------------------
 
YELLOW 	    = \033[0;93m
BOLD_YELLOW = \033[1;33m
DEF_COLOR   = \033[0m
