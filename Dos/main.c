#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* pArchivo;

    pArchivo = fopen("Texto.txt", "w");
    fprintf(pArchivo, "Hola\nQue\nHace");
    fclose(pArchivo);
    /**Lectura hasta el final del archivo mediante el cursor*/
    char texto[3][50];
    int i = 0;
    pArchivo = fopen("Texto.txt", "r");
    while(!feof(pArchivo))
    {
        fgets(texto[i], 50, pArchivo);
        i++;
    }
    fclose(pArchivo);
    for(i = 0; i < 3; i++)
    {
        puts(texto[i]);
    }
    return 0;
}
