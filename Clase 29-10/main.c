#include <stdio.h>
#include <stdlib.h>

int guardarArrayEnTxt(int array[], int tamanio, char nombre[]);
int leerArrayEnTxt(int array[], int tamanio, char nombre[]);
int guardarArrayEnBin(int array[], int tamanio, char nombre[]);
int leerArrayEnBin(int array[], int tamanio, char nombre[]);

int main()
{
    int listado[10];
    int listadoDos[10];
    int listadoTres[10];
    int i;
    for(i = 0; i < 10; i++)
    {
        listado[i] = i + 1;
    }

    /*
    pArchivo = fopen("ArchivoUno.bin", "wb");
    int y = fwrite(listado, sizeof(int), 10, pArchivo);
    fclose(pArchivo);

    pArchivo = fopen("ArchivoUno.bin", "rb");
    fread(&listadoDos, sizeof(int), 10, pArchivo);
    fclose(pArchivo);
    */

    guardarArrayEnTxt(listado, 10, "Archivo.txt");
    leerArrayEnTxt(listadoDos,10, "Archivo.txt");
    for(i = 0; i < 10; i++)
    {
        printf("%d\n",listadoDos[i]);
    }

    guardarArrayEnBin(listado, 10, "ArchivoUno.bin");
    leerArrayEnBin(listadoTres, 10, "ArchivoUno.bin");
    for(i = 0; i < 10; i++)
    {
        printf("%d\n",listadoTres[i]);
    }

    return 0;
}

int guardarArrayEnTxt(int array[], int tamanio, char nombre[])
{
    FILE* pArchivo;
    pArchivo = fopen(nombre, "w");
    int y = fwrite(array, sizeof(int), tamanio, pArchivo);
    fclose(pArchivo);
    if(y == tamanio)
    {
        return 1;
    }
    return 0;
}

int leerArrayEnTxt(int array[], int tamanio, char nombre[])
{
    FILE* pArchivo;
    pArchivo = fopen(nombre, "r");
    fread(array, sizeof(int), tamanio, pArchivo);
    fclose(pArchivo);
    return 0;
}

int guardarArrayEnBin(int array[], int tamanio, char nombre[])
{
    FILE* pArchivo;
    pArchivo = fopen(nombre, "wb");
    int y = fwrite(array, sizeof(int), tamanio, pArchivo);
    fclose(pArchivo);
    if(y == tamanio)
    {
        return 1;
    }
    return 0;
}

int leerArrayEnBin(int array[], int tamanio, char nombre[])
{
    FILE* pArchivo;
    pArchivo = fopen(nombre, "rb");
    fread(array, sizeof(int), tamanio, pArchivo);
    fclose(pArchivo);
    return 0;
}

int guardarArrayEnTxtDos(int array[], int tamanio, char nombre[])
{
    FILE* pArchivo;
    int i;
    pArchivo = fopen(nombre, "w");
    for(i = 0; i < tamanio, i++)
    {
        fprintf(pArchivo, "%d", array[i]);
    }
    fclose(pArchivo);
    return 0;
}

int leerArrayEnTxtDos(char array[], int tamanio, char nombre[])
{
    FILE* pArchivo;
    pArchivo = fopen(nombre, "r");
    fgets(array, tamanio, pArchivo);
    fclose(pArchivo);
    return 0;
}
