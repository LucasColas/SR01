#!/bin/bash
gcc -o sortie1 sortie1.c
./sortie1

if [ $? -eq 0 ]
then
  echo "42"
else
  echo "Pas 42"
fi
