#!/bin/sh

#Run the program with debug mode, by setting as "set x"
#set -x 

echo "Script Name: $0"

function func {
    for var in $*
    do
        let i=i+1
        echo "The \$${i} argument is: ${var}"
    done
    
}
func
echo "Total count of arguments: $#"
