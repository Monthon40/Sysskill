#!/bin/bash
#read -p "Input zip file and directory: " zip path

name=$(unzip -q -d "$2" "$1")
cd "$2"
find . -mindepth 2 -type f -print -exec mv {} . \;
find . -type d -empty -delete ;


