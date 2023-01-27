// ParalellArrayLab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <omp.h>
#include <iostream>
#include <stdio.h>

#define N 1000 // La cantidad de elementos a manejar en los arreglos 
#define chunk 100 // El tamaño que tendrán los pedazos de los arreglos para que cada hilo creado se encargue de esta cantidad de elementos
#define mostrar 10 // Permitirá manejar la cantidad de datos a imprimir

void imprimeArreglo(float *d);


int main() {
    std::cout << "Sumando Arreglos en Paralelo\n";
    float a[N], b[N], c[N];
    int i;
    //semilla
    srand((unsigned) time(NULL));
    //Generamos valores aleatorios 
    for (i = 0; i < N; i++) {
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }
    int pedazos = chunk;
#pragma omp parallel for \
    shared(a,b,c,pedazos) private(i) \
    schedule(static,pedazos)

    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }
       

    std::cout << "Imprimiento los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiento los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiento los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(c);

}


void imprimeArreglo(float *d) {
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
