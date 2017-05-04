#! /bin/sh

greeting='Hello        world!'
echo $greeting" now with spaces: $greeting"

birthdate='Jan 21 1989'
name='Virat'

if [ "$name" == "Virat" ]; then
	echo "Proceed for DOB"
fi

if [ "$birthdate" == "Jan 21 1989" ]; then
	echo "Date of birth is correct"
fi

echo "$1 $2 $3"

my_array=( apple orange banana guava "apricot" )
echo ${#my_array[@]}
echo ${my_array[${#my_array[@]}-1]}
for i in ${my_array[@]}; do
	echo $i
done

cost_banana=10
cost_apple=50
cost_bag=2

total=$(((2*$cost_banana)+(1*$cost_apple)+$cost_bag))
echo "Fruit with bag cost:"$total

echo ""
STRING="this is a string"
echo ${#STRING}

STRING="this is a string"
POS=1
LEN=3
echo ${STRING:$POS:$LEN}
echo ${STRING:1}
echo ${STRING:12}

STRING="to be or not to be"
echo $STRING
echo ${STRING[@]}
#Replace first occurrence of substring with replacement
echo ${STRING[@]/be/eat}
#Replace all occurrences of substring
echo ${STRING[@]//be/eat}
#Delete all occurrences of substring (replace with empty string)
echo ${STRING[@]// not/}
#Replace occurrence of substring if at the beginning of $STRING
echo ${STRING[@]/#to be/eat now}
#Replace occurrence of substring if at the end of $STRING
echo ${STRING[@]/%be/eat}
