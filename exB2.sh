#!/bin/bash

mkdir lab7
cd lab7

touch notes.txt script.sh
chmod 640 notes.txt

chmod -rwx script.sh
chmod u+rwx script.sh
chmod g+rx script.sh
chmod o-rwx script.sh

ls -l