#!/bin/bash

directory=$1

for i in "$(ls $DIRECTORY | grep .txt)"; do
    echo "Renamed $1 to .txt.bak"
    mv "$i" "$i.bak"
done