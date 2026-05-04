#!/bin/bash

[[ $# -eq 1 ]] || { echo "Usage: $0 path"; exit 1; }

NAME=$1

if [[ -e $NAME ]]; then
    echo "file yes"
    if [[ -r $NAME ]];
        echo "read too"
        echo "number of lines:"
        wc --lines $NAME
        echo "number of words:"
        wc --words $NAME
        echo "number of characters:"
        wc --chars $NAME
    else
        echo "read nope"
    fi
else
    echo "file nope"
fi