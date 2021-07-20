# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: philippe <philippe@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 02:26:02 by pminne            #+#    #+#              #
#    Updated: 2021/07/20 21:32:02 by philippe         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CPP	=	clang++

CFLAGS	=	-Wall -Wextra -fsanitize=address -g3

SRCS	=	main.cpp\
			vector.cpp\

OBJS	=	$(SRCS:.cpp=.o)

EXEC	=	tests

INSTRUCTIONS = "Compilation done, run ./unit_tests$'\n\
				-l to list all availaible tests$'\n\
				-t to list all availaible tags$'\n\
				-n to select a specific suite name$'\n\
				-d <yes> to show test duration$'\n\
				-benchmark-no-analysis"

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
