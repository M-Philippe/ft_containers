# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: philippe <philippe@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 02:26:02 by pminne            #+#    #+#              #
#    Updated: 2021/07/02 18:36:40 by philippe         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CPP	=	clang++

CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address -g3

SRCS	=	main.cpp\
			vector.cpp\

OBJS	=	$(SRCS:.cpp=.o)

EXEC	=	unit_tests

all:	$(EXEC)

$(EXEC):	$(OBJS)
	$(CPP) -o $@ $^ $(CFLAGS)

%.o:	%.cpp
	$(CPP) -o $@ -c $< $(CFLAGS) 

fclean	:	clean
	rm -rf $(EXEC)

clean	:
	rm -rf $(OBJS)

re:		fclean all

.PHONY: all fclean clean re
