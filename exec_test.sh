#! /usr/bin/env bash

#./ft_test > ft_results
#./std_test > std_results

RED="\e[31m"
NC="\e[37m"
GREEN="\e[32m"

if [ "$1" = "-show" ]
then
	./ft_test
	./std_test
	exit
elif [ "$1" = "-leaks" ]
then
	valgrind --leak-check=full --show-leak-kinds=all ./ft_test > /dev/null
	valgrind --leak-check=full --show-leak-kinds=all ./std_test > /dev/null
	exit
fi

if [ "$OSTYPE" = "linux-gnu" ]
then
	/usr/bin/time --format="%C took %e seconds" ./ft_test > ft_results.txt
	/usr/bin/time --format="%C took %e seconds" ./std_test > std_results.txt
elif [ "$OSTYPE" = "mac"* ]
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
