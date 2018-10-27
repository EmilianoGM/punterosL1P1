#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numero;
    char letra;
}eDato;

int main()
{
    FILE* pArchivo;
    /**< ESCRITURA DE ARCHIVO BINARIO*/
    eDato datoUno;
    datoUno.numero = 7;
    datoUno.letra = 'H';
    pArchivo = fopen("ArchivoDos.bin", "wb");
    int y = fwrite(&datoUno, sizeof(eDato), 1, pArchivo);
    fclose(pArchivo);
    /**< LECTURA DE ARCHIVO BINARIO*/
    eDato datoDos;
    pArchivo = fopen("ArchivoDos.bin", "rb");
    fread(&datoDos, sizeof(eDato), 1, pArchivo);
    fclose(pArchivo);
    printf("%d - %c", datoDos.numero, datoDos.letra);
    return 0;
}
