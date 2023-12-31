#!/bin/bash

# Compilación de los archivos .cpp metodo recurso de nucleos
echo "Compilando hilo 1..."
g++ -o hilo1 determinante.cpp -lpthread
echo "Compilando hilo 2..."
g++ -o hilo2 AdjTraspuesta.cpp -lpthread
echo "Compilando hilo 3..."
g++ -o hilo3 hilo3.cpp -lpthread

# Verificar si la compilación fue exitosa antes de ejecutar los programas
if [ $? -eq 0 ]; then
    echo "Compilación exitosa. Ejecutando los hilos..."

    # Ejecutar hilo1 en el núcleo 0
    taskset -c 0 ./hilo1 &
    PID1=$!

    # Ejecutar hilo2 en el núcleo 1
    taskset -c 1 ./hilo2 &
    PID2=$!

    # Ejecutar hilo3 en el núcleo 2
    taskset -c 2 ./hilo3 &
    PID3=$!

    # Esperar a que todos los procesos finalicen
    wait $PID1
    wait $PID2
    wait $PID3

    echo "Todos los hilos han terminado."
else
    echo "Error en la compilación. Por favor, corrige los errores antes de ejecutar los programas."
fi
