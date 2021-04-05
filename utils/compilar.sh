#!/bin/bash
for i in *; do
  if [ ${i: -2} = '.c' ] && [ -f $i ]; then
    gcc -o ${i/.c} -g -Wall $i -lm
    echo "$i compilado! :)"
  fi
done
