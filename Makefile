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

$(NAME):		${OBJS}
				${AR} ${NAME} ${OBJS}

all:			${NAME}

clean:
				${RM} ${OBJS} ${BONUS_OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

bonus:			${OBJS} ${BONUS_OBJS}
				${AR} ${NAME} ${OBJS} ${BONUS_OBJS}

.PHONY:			all clean fclean re bonus
