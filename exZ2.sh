#!/bin/bash

if [[ -e commedia.txt ]]; then
    echo "File already downloaded"
else
    wget https://www.gutenberg.org/cache/epub/1012/pg1012.txt
    mv pg1012.txt commedia.txt
    echo "'pg1012.txt' renamed to 'commedia.txt'"
fi

echo "Canti in Inferno: $(grep -c "Inferno" commedia.txt)"
echo "Canti in Purgatorio: $(grep -c "Purgatorio" commedia.txt)"
echo "Canti in Paradiso: $(grep -c "Paradiso" commedia.txt)"

echo "First lines after each 'Canto': $(grep "Canto" -A 6 commedia.txt)"

echo "Occurrences of 'quanto': $(grep -c "quanto" commedia.txt)"

