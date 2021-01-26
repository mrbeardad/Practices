#!/bin/bash

while [[ "$OPTIND" -le "$#" ]] ;do
    while getopts o: name ;do
        echo "opt:-$name  arg:$OPTARG"
    done
    name=$(eval echo \$$OPTIND)
    if [[ "$name" != "-" && "$name" != "--" && ! "$name" =~ [^-]* ]] ;then
        break
    fi
    echo -- $name
    ((++OPTIND))
done
