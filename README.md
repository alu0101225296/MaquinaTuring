# COMPLEJIDAD COMPUTACIONAL
## PRÁCTICA 2: Programar un simulador de una Máquina de Turing
###### Pablo Bande Sánchez - Girón 
## Descripción de máquina

Máquina de Turing con escritura y movimientos independientes, únicos movimientos (L y R) con cinta infinita en ambas direcciones.
## Compilación y ejecución
```console
// directorio /bin
$ make
$ ./maquina test.txt
```
## Ejercicios
#### 1. MT que reconozca el lenguaje L = { a^nb^m | m < n, n > 0 }
![ej1](https://github.com/alu0101225296/MaquinaTuring/blob/main/resources/ej1.png?raw=true)
```txt
# a^n b^m | n > 0 , n > m
q0 q1 q2 q3 q4 q5
a b
a b .
q0
.
q4
q0 a q1 . R
q1 a q1 a R
q1 b q2 b R
q1 . q3 . L
q2 b q2 b R
q2 . q3 . L
q3 . q4 . L
q3 a q4 . L
q3 b q5 . L
q5 a q5 a L
q5 b q5 b L
q5 . q0 . R
```
#

#### 2. MT que reciba como parámetro una cadena binaria y separe los ceros y los unos,
colocando en la cinta primero los ceros y después los unos dejando un espacio en
blanco entre ellos.
![ej2](https://github.com/alu0101225296/MaquinaTuring/blob/main/resources/ej2.png?raw=true)
```txt
# Separa 0 y 1
q0 q1 q2 q3 q4 q5 q6 q7 q8 q9 q10
0 
0 1 x .
q0
.
q10
q0 x q0 x R
q0 1 q0 1 R
q0 0 q1 x L
q1 0 q1 0 L
q1 1 q1 1 L
q1 x q1 x L
q1 . q2 . L
q2 0 q2 0 L
q2 . q3 0 R
q3 0 q3 0 R
q3 . q0 . R
q0 . q4 . L
q4 x q4 x L
q4 1 q4 1 L
q4 . q5 . R
q5 1 q5 1 R
q5 x q6 x R
q6 x q6 x R
q6 1 q7 x L
q7 x q7 x L
q7 1 q8 1 R
q7 . q8 . R
q8 x q5 1 R
q6 . q9 . L
q9 x q9 . L
q9 1 q10 1 R
q9 . q10 . R
q5 . q10 . R
```
