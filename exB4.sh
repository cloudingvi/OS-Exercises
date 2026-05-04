#!/bin/bash

echo "Number of users:"
cat /etc/passwd | wc -l

echo "First 5 entries:"
head -n 5 /etc/passwd

if [[ -r /etc/passwd ]]; then
    echo "readable"
else
    echo "readablen't"
fi