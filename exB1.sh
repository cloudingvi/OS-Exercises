#!/bin/bash

[[ $# -eq 1 ]] || { echo "Usage: $0 path"; exit 1; }

NAME=$1

if [[ -e $NAME ]]; then
    echo "exists"

    if [[ -f $NAME ]]; then
        echo "file"
    elif [[ -d $NAME ]]; then
        echo "directory"
    elif [[ -L $NAME ]]; then
        echo "link"
    else
        echo "something"
    fi

    ls -ld $NAME

else
    echo "existn'ts"
fi