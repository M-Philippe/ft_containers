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

FT_FLAGS	=	-Wall -Wextra -g3
STD_FLAGS = -Wall -Wextra -g3 -DSTD_TEST

SRCS	=	src/main.cpp\
				src/vector/vector_test.cpp\

FT_OBJS	=	$(SRCS:%.cpp=ft_objs/%.o)
STD_OBJS = $(SRCS:%.cpp=std_objs/%.o)

EXEC_FT	=	ft_test
EXEC_STD = std_test

all:	Makefile $(EXEC_FT) $(EXEC_STD)
	@echo "\033[0;32mAll compilation done, run ./exec_test.sh"

$(EXEC_FT):	$(FT_OBJS)
	@echo "\033[0;32mCompiling ft_test"
	@$(CPP) -o $@ $^ $(FT_FLAGS)

$(EXEC_STD):	$(STD_OBJS)
	@echo "\033[0;32mCompiling std_test"
	@$(CPP) -o $@ $^ $(STD_FLAGS)

ft_objs/%.o:	%.cpp src/**/*.hpp
	@mkdir -p $(@D)
	@$(CPP) -o $@ -c $< $(FT_FLAGS)

std_objs/%.o: %.cpp src/**/*.hpp
	@mkdir -p $(@D)
	@$(CPP) -o $@ -c $< $(STD_FLAGS)

fclean	:	clean
	@rm -rf $(EXEC_FT) $(EXEC_STD)

clean	:
	@rm -rf ft_objs
	@rm -rf std_objs

re:		fclean all

.PHONY: all fclean clean re instructions
