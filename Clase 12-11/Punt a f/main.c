#include <stdio.h>
#include <stdlib.h>

void mostrar(int numero);

void manejador(void (*pFuncion)(int), int valor);

int main()
{
    int num = 9;
    void (*pFuncion)(int);
    pFuncion = mostrar;
    pFuncion(num);
    manejador(pFuncion, 8);
    return 0;
}

void mostrar(int numero)
{
    printf("HOLA %d\n", numero);
}

void manejador(void (*pFuncion)(int), int valor)
{
    pFuncion(valor);
}
