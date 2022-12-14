# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmilagro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 19:27:52 by cmilagro          #+#    #+#              #
#    Updated: 2022/03/15 19:27:59 by cmilagro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN 					=	\033[0;32m
RED						=	\033[0;31m
RESET					=	\033[0m

NAME					=	client
NAME_2					=	server
NAME_BONUS				=	client_bonus
NAME_2_BONUS			=	server_bonus
NAME_3					=	minitalk
CC						=	gcc
FLAGS					=	-Wall -Wextra -Werror
LIBFT					=	$(LIBFT_DIR)libft.a
LIBFT_DIR				=	./libft/
LIBFT_HEAD				=	-I $(LIBFT_DIR)includes/
SOURCES_DIR				=	sources/
CLIENT_SOURCE			=	client.c
SERVER_SOURCE			=	server.c
CLIENT_SOURCE_BONUS		=	client_bonus.c
SERVER_SOURCE_BONUS		=	server_bonus.c
OBJECTS_DIR				=	objects/
OBJECTS_BONUS_DIR		=	objects_bonus/
CLIENT_OBJECT			=	$(patsubst %.c, %.o, $(CLIENT_SOURCE))
SERVER_OBJECT			=	$(patsubst %.c, %.o, $(SERVER_SOURCE))
CLIENT					=	$(addprefix $(OBJECTS_DIR), $(CLIENT_OBJECT))
SERVER					=	$(addprefix $(OBJECTS_DIR), $(SERVER_OBJECT))
CLIENT_BONUS_OBJECT		=	$(patsubst %client_bonus.c, %client_bonus.o, $(CLIENT_SOURCE_BONUS))
SERVER_BONUS_OBJECT		=	$(patsubst %server_bonus.c, %server_bonus.o, $(SERVER_SOURCE_BONUS))
CLIENT_BONUS			=	$(addprefix $(OBJECTS_BONUS_DIR), $(CLIENT_BONUS_OBJECT))
SERVER_BONUS			=	$(addprefix $(OBJECTS_BONUS_DIR), $(SERVER_BONUS_OBJECT))



all						:	$(NAME) $(NAME_2)

$(NAME)					:	$(LIBFT) $(OBJECTS_DIR) $(CLIENT)
						@$(CC) $(FLAGS) $(CLIENT) $< -o $(NAME)

$(NAME_2)				: $(LIBFT) $(OBJECTS_DIR) $(SERVER)
						@$(CC) $(FLAGS) $(SERVER) $< -o $(NAME_2)
						@echo "\n$(NAME_3):$(GREEN)$(NAME_2) was created 🤰$(RESET)"
						@echo "$(NAME_3): $(GREEN)$(NAME) was created 🌐$(RESET)"

$(OBJECTS_DIR)			:
						@mkdir -p $(OBJECTS_DIR)
						@echo "$(NAME_3): $(GREEN)objects directory was created 🛒$(RESET)"

$(OBJECTS_DIR)%.o		: $(SOURCES_DIR)%.c
						@$(CC) $(FLAGS) -c $(LIBFT_HEAD) $< -o $@
						@echo "🎾\c"

$(LIBFT)				:
						@echo "libft.a: $(GREEN) creating 📔...$(RESET)"
						@$(MAKE) -sC $(LIBFT_DIR)


$(OBJECTS_BONUS_DIR)	:
						@mkdir -p $(OBJECTS_BONUS_DIR)
						@echo "$(NAME_3): $(GREEN)objects directory was created 🛒$(RESET)"

$(OBJECTS_BONUS_DIR)%.o : $(SOURCES_DIR)%.c
						@$(CC) $(FLAGS) -c $(LIBFT_HEAD) $< -o $@
						@echo "🏅\c"

bonus 					:	$(NAME_BONUS) $(NAME_2_BONUS)

$(NAME_BONUS)			:	$(LIBFT) $(OBJECTS_BONUS_DIR) $(CLIENT_BONUS)
						@$(CC) $(FLAGS) $(CLIENT_BONUS) $< -o $(NAME_BONUS)


$(NAME_2_BONUS)			:	$(LIBFT) $(OBJECTS_BONUS_DIR) $(SERVER_BONUS)
						@$(CC) $(FLAGS) $(SERVER_BONUS) $< -o $(NAME_2_BONUS)
						@echo "\n$(NAME_3):$(GREEN)$(NAME_2) was created ⭐🤰⭐$(RESET)"
						@echo "$(NAME_3): $(GREEN)$(NAME) was created ⭐🌐⭐$(RESET)"
							
clean					:
						@$(MAKE) -sC $(LIBFT_DIR) clean
						@rm -rf $(OBJECTS_DIR)
						@rm -rf $(OBJECTS_BONUS_DIR)
						@echo "$(RED)$(OBJECTS_DIR): was deleted 🗑$(RESET)"
						@echo "$(RED)client.o and server.o were deleted 🗑$(RESET)"

fclean					: clean
						@rm -rf $(LIBFT)
						@echo "$(RED)$(LIBFT): was deleted 🗑$(RESET)"
						@rm -rf $(NAME) $(NAME_2)
						@rm -rf $(NAME_BONUS) $(NAME_2_BONUS)
						@echo "$(RED)$(NAME) and $(NAME_2): were deleted 🗑$(RESET)"

re						:
						@$(MAKE) fclean
						@$(MAKE) all

.PHONY					:	all clean fclean re bonus
