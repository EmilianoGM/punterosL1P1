#include <stdio.h>
#include <stdlib.h>

//void escribirArchivoTexto(FILE* pArchivo, char[] texto);

int main()
{
    FILE* pArchivo;
    /**ESCRITURA */
    pArchivo = fopen("Texto.txt", "w");
    fprintf(pArchivo, "Hola %s mundo\nEstoy programando", "a todo el");
    fclose(pArchivo);
    /**LECTURA*/
    char texto[50], otra[50];
    pArchivo = fopen("Texto.txt", "r");
    fgets(texto, 50, pArchivo);
    fgets(otra, 50, pArchivo);
    fclose(pArchivo);
    printf("%s", texto);
    printf("%s", otra);
    return 0;
}
/*
void escribirArchivoTexto(FILE* pArchivo, char[] texto)
{
    pArchivo = fopen("Texto.txt", "w");
    fprintf(pArchivo, texto);
    fclose(pArchivo);
}
*/
