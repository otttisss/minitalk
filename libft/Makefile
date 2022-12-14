GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME	= 	libft.a
SRC_DIR	=	./sources/
SRC_L	=	ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_toupper.c \
			ft_tolower.c ft_strlen.c ft_strlcpy.c \
			ft_strchr.c ft_strrchr.c ft_bzero.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
			ft_memset.c ft_strlcat.c ft_strncmp.c ft_strnstr.c \
			ft_atoi.c ft_strdup.c ft_calloc.c ft_substr.c ft_strtrim.c \
			ft_strjoin.c ft_split.c ft_itoa.c ft_striteri.c ft_strmapi.c \
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c	\
			ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c \
			ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c \
			ft_lstclear.c	ft_lstiter.c		ft_lstmap.c	\
			get_next_line.c	ft_wdcounter.c	ft_printf.c printf_utils.c

OBJ_D	=	objects/
OBJ_L	=	$(patsubst %.c, %.o, $(SRC_L))
OBJ	=	$(addprefix $(OBJ_D), $(OBJ_L))

INCLD	=	-I$(HEAD_D)
HEAD_L	=	libft.h ft_printf.h
HEAD_D	=	./includes/
HEADERS	=	$(addprefix $(HEAD_D), $(HEAD_L))

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -c
RM	=	rm -f


all	:	$(NAME)

$(NAME)	:	$(OBJ_D) $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"


$(OBJ_D):
	@mkdir -p $(OBJ_D)
	@echo "$(NAME): $(GREEN)$(OBJ_D) was created$(RESET)"
$(OBJ_D)%.o	:	$(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(CFLAGS) $(INCLD) $< -o $@
	@echo "$(GREEN)🍪$(RESET)\c"

clean:
	@rm -rf $(OBJ_D)
	@echo "$(NAME): $(RED)$(OBJ_D) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
