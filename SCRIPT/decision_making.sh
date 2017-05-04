#!/bin/sh

number=10
apples=12
king=geroge

if [ $number -gt 15 ]; then
	echo 1
fi
if [ $number -eq $apples ]; then
	echo 2
fi
if [[ ($apples -eq 12) || ($king = "luis") ]]; then
	echo 3
fi
if [[ $(($number+$apples)) -le 32 ]]; then
	echo 4
fi 

NUMBERS=(951 402 984 651 360 69 408 319 601 485 980 507 725 547 544 615 83 165 141 501 263 617 865 575 219 390 237 412 566 826 248 866 950 626 949 687 217 815 67 104 58 512 24 892 894 767 553 81 379 843 831 445 742 717 958 609 842 451 688 753 854 685 93 857 440 380 126 721 328 753 470 743 527)
#i=238
# write your code here
for i in ${NUMBERS[@]}; do
	if [ $i -le 237 ]; then
    	rem=$(($i % 2))
    	if [ $rem -eq 0 ]; then
    		echo $i;
        fi
    
    else
    	continue
    fi
done
