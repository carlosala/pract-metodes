#!/bin/bash
if [[ $# -eq 1 ]]; then
  ./pb1 $1
  if [[ -f out.txt ]]; then
    gnuplot -p -e "plot 'out.txt' using 1:2 with lines title 'funció', 'out.txt' using 1:3 with lines title 'equiespaciats', 'out.txt' using 1:4 with lines title 'chebyshev'"
  else
    echo "Fitxer out.txt no trobat."
  fi
else
  echo "Cal executar l'script de la següent manera: ./plot.sh n"
fi
