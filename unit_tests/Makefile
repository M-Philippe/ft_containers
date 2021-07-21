# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: philippe <philippe@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 02:26:02 by pminne            #+#    #+#              #
#    Updated: 2021/07/21 15:57:51 by philippe         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CPP	=	clang++

CFLAGS	=	-Wall -Wextra -fsanitize=address -g3

SRCS	=	unit_tests.cpp\
			vector.cpp\

OBJS	=	$(SRCS:.cpp=.o)

EXEC	=	tests

INSTRUCTIONS = "Compilation done, run ./$(EXEC)$'\n\
				-l to list all availaible tests$'\n\
				-t to list all availaible tags$'\n\
				-n to select a specific suite name$'\n\
				-d <yes> to show test duration$'\n\
				-benchmark-no-analysis$'\n"

all:	$(EXEC)

$(EXEC):	$(OBJS)
	@$(CPP) -o $@ $^ $(CFLAGS)
	@echo $(INSTRUCTIONS)
	@echo "make instructions for a reminder of those instructions"

%.o:	%.cpp
	@$(CPP) -o $@ -c $< $(CFLAGS) 

fclean	:	clean
	@rm -rf $(EXEC)

clean	:
	@rm -rf $(OBJS)

re:		fclean all

instructions:
	@echo $(INSTRUCTIONS)

.PHONY: all fclean clean re instructions
