#!/bin/bash

DIRECTORY=$1
COUNT=0

for i in "$(ls $DIRECTORY)"; do
    [[ -f $i ]] && COUNT=$((COUNT + 1))
done

echo "Number of regular files: $COUNT"
echo "Number of directories: $(ls -d $DIRECTORY | wc -l)"
echo "Number of .sh files: $(ls $DIRECTORY | grep .sh | wc -l)"