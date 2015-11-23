#!/bin/bash

mkdir $1
find *.root -maxdepth 1 -type f -mmin +5 |head -1000| xargs mv -t $1
