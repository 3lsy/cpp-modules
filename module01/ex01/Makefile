# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 09:39:46 by echavez-          #+#    #+#              #
#    Updated: 2024/02/10 01:06:55 by echavez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	level01

#***************** SRC* *******************#

DIRSRC		=	./

SRC			=	Zombie.cpp zombieHorde.cpp main.cpp

SRCS		=	$(SRC)

#***************** DEPS ******************#

DIROBJ		=	./

OAUX		=	$(SRCS:%=$(DIROBJ)%)
DEPS		=	$(OAUX:.cpp=.d)
OBJS		=	$(OAUX:.cpp=.o)

ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS		=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -ansi -pedantic -g
	endif
else
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
endif

CC			=	/usr/bin/clang++
RM			=	/bin/rm -f
ECHO		=	/bin/echo -e

#************************ DEPS COMPILATION *************************

%.o		:		../$(DIRSRC)/%.cpp
				@$(CC) $(CFLAGS) -MMD -o $@ -c $<

#************************ MAIN COMPILATION *************************

$(NAME)	:		$(OBJS)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean	:
				@($(RM) $(OBJS))
				@($(RM) $(DEPS))
				@$(ECHO) $(RED)'> Directory cleaned'$(E0M)

all		:		$(NAME)

fclean	:		clean
				@$(RM) $(NAME)
				@$(ECHO) $(RED)'> Executable removed'$(E0M)

re		:		fclean all

.PHONY	:		all clean re

-include $(DEPS)