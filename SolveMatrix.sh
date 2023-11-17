#!/bin/bash

# Compilación de los archivos .cpp
echo "Compilando hilo 1 det..."
g++ -o hilo1 determinante.cpp -lpthread
echo "Compilando hilo 2 (adj)T..."
g++ -o hilo2 AdjTraspuesta.cpp -lpthread
echo "Compilando hilo 3 ..."
g++ -o hilo3 hilo3.cpp -lpthread

# Verificar si la compilación fue exitosa antes de ejecutar los programas
if [ $? -eq 0 ]; then
    echo "Compilación exitosa. Ejecutando los hilos..."

    # Ejecutar los programas en segundo plano

    ./hilo1 &
    PID1=$!
    echo "Se ha ejecutado el hilo 1 \n"

    ./hilo2 &
    PID2=$!
    echo "Se ha ejecutado el hilo 2 \n"

    ./hilo3 &
    PID3=$!
    echo "Se ha ejecutado el hilo 3 \n"
    echo "EL hilo 3 esta vacio, solo esta indicado para denotar \n"
    echo "que se puedes seguir ingresando mas funciones a desarrollar \n"
    echo "Con el comando bash SolveMatrix.sh \n"

    # Esperar a que todos los procesos finalicen
    wait $PID1
    wait $PID2
    wait $PID3

    echo "Todos los hilos han terminado."
else
    echo "Error en la compilación. Por favor, corrige los errores antes de ejecutar los programas."
fi
