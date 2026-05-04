#!/bin/bash

touch original.txt
echo "hi" >> original.txt
ln original.txt hard.txt
ln -s original.txt soft.txt

rm original.txt

echo "hard link contents:"
cat hard.txt
echo "soft link contents:"
cat soft.txt