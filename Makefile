# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 13:12:13 by vkhlghat          #+#    #+#              #
#    Updated: 2022/03/17 15:43:51 by vkhlghat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			${wildcard ./mandatory/*.c}

OBJS			= ${SRCS:.c=.o}
		
BONUS = 		${wildcard ./bonus/*.c}
	  			
BONUS_OBJS		= ${BONUS:.c=.o}

CC				= cc
RM				= rm -f
AR				= ar rcs
CFLAGS			= -Wall -Wextra -Werror -I ./

NAME			= libft.a

.c.o:
				@${CC} ${CFLAGS} -o ${<:.c=.o} -c $<

all:			${NAME}

$(NAME):		${OBJS}
				@${AR} ${NAME} ${OBJS}
				@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
				@${RM} ${OBJS} ${BONUS_OBJS}
				@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@${RM} ${NAME}
				@echo "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

bonus:			${OBJS} ${BONUS_OBJS}
				@${AR} ${NAME} ${OBJS} ${BONUS_OBJS}
				@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

.PHONY:			all clean fclean re bonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
