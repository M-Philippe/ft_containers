#./ft_test > ft_results
#./std_test > std_results

GREEN="\033[0;32m"
RED="\033[0;31m"
BLACK="\033[0;37m"

/usr/bin/time --format="%C took %e seconds" ./ft_test > ft_results.txt
/usr/bin/time --format="%C took %e seconds" ./std_test > std_results.txt

diff ft_results.txt std_results.txt > /dev/null
if [ $? -eq 0 ]
then
	echo "$GREEN=== VectorTest OK :) ===$BLACK"
else
	echo "$RED=== VectorTest BAD :'( ===$BLACK"
	echo "$(diff ft_results.txt std_results.txt)"
fi

echo "$GREEN=== All tests done ===$BLACK"
