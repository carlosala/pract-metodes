----- INSTRUCCIONES PARA LA COMPILACIÓN -----
Todos los códigos deberán ser compilados con la misma instrucción.
Usando un ejemplo de un fichero pb1a.c:
gcc -o pb1a -g -Wall pb1a.c -lm 

Se ha dispuesto un fichero ejecutable compilar.sh para compilar todos los archivos.
Debe ser ejecutado del siguiente modo: ./compilar.sh

----- INSTRUCCIONES DE USO -----

- PROBLEMA 1 -
El binario pb1a debe ser ejecutado sin argumentos: ./pb1a
El binario pb1b debe ser ejecutado sin argumentos: ./pb1b

- PROBLEMA 2 -
El binario pb2a debe ser ejecutado con 3 argumentos: ./pb2a a b c
donde a, b y c forman la ecuación de 2o grado ax^2+bx+c=0
El binario pb2b se ejecuta del mismo modo.

- PROBLEMA 3 -
El binario pb3a debe ser ejecutado con n argumentos: ./pb3a n1 n2 n3...
donde ni son las componentes del vector del cual queremos calcular la varianza.
Los binarios pb3c1 y pb3c2 deben ser ejecutados sin argumentos: ./pb3c1 (./pb3c2)

- PROBLEMA 4 -
El binario pb4a debe ser ejecutado con 1 argumento: ./pb4a n
donde n es el número de terminos a sumar.
El binario pb4b y pb4d se ejecutan del mismo modo.
