#! /usr/bin/env bash

#./ft_test > ft_results
#./std_test > std_results

RED="\033[31m"
NC="\033[37m"
GREEN="\033[32m"

if [ "$1" = "-show" ]
then
	./ft_test
	./std_test
	exit
elif [ "$1" = "-help" ]
then
	echo "-show to show tests results."
	echo "-leaks to show memory usage."
	echo "-unit_test to show mli42_tests"
	exit
elif [ "$1" = "-leaks" ]
then
	valgrind --leak-check=full --show-leak-kinds=all ./ft_test > /dev/null
	valgrind --leak-check=full --show-leak-kinds=all ./std_test > /dev/null
	exit
elif [ "$1" = "-compile" ]
then
	clang++ -g3 -Wall -Wextra -fsanitize=address -std=c++98 ./containers_test/srcs/$2/$3
	exit
elif [ "$1" = "-unit_test" ]
then
	cd containers_test
	if [ "$2" = "all" ]
	then
		./do.sh vector
		./do.sh stack
		./do.sh map
	else
		./do.sh $2
	fi
	exit
fi

if [ "$OSTYPE" = "linux-gnu" ]
then
	/usr/bin/time --format="%C took %e seconds" ./ft_test > ft_results.txt
	/usr/bin/time --format="%C took %e seconds" ./std_test > std_results.txt
elif [ "$OSTYPE" = "darwin20" ]
then
	time ./ft_test > ft_results.txt
	time ./std_test > std_results.txt
else
	echo -e "${RED} Unknown platform, impossible to display execution time.${NC}"
	./ft_test > ft_results.txt
	./std_test > std_results.txt
fi

diff ft_results.txt std_results.txt > /dev/null
if [ $? -eq 0 ]
then
	echo -e "${GREEN}=== VectorTest OK :) ===${NC}"
else
	echo -e "${RED}=== VectorTest BAD :'( ===${NC}"
	echo -e "$(diff ft_results.txt std_results.txt)"
fi

echo -e "$GREEN=== All tests done ===${NC}"
