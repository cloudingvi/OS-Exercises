#!/bin/bash

[[ $# -eq 1 ]] || { echo "Usage: $0 filePath"; exit 1; }

NAME=$1

if [[ -e $NAME ]]; then
    echo "file yes"
    if [[ -r $NAME ]]; then
        echo "read too"
        echo "number of lines:"
        wc -l $NAME
        echo "number of words:"
        wc -w $NAME
        echo "number of characters:"
        wc -m $NAME

        head -n 7 $NAME | tail -n 4

    else
        echo "read nope"
    fi
else
    echo "file nope"
fi