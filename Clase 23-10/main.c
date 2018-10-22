#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numero;
    char letra;
}eDato;

eDato* funcion(int numero, char letra);
int eDato_getNumero(eDato* this, int numero);
int eDato_getLetra(eDato* this, char letra);
int eDato_mostrar(eDato* this);

int main()
{
    /*
    eDato datoUno = {9, 'c'};
    eDato* pDato;
    pDato = &datoUno;
    int x;
    x = (*pDato).numero;
    printf("%d", x);
    */

    /*
    eDato* pDatoUno;
    pDatoUno = funcion(5, 'w');
    printf("%d - %c\n", pDatoUno->numero, pDatoUno->letra);
    eDato* pDatoDos;
    pDatoDos = funcion(1, 'u');
    printf("%d - %c\n", pDatoDos->numero, pDatoDos->letra);
    */

    /*
    eDato listaDato[2] = {{7, 'a'}, {2, 'r'}};
    eDato* pDato;
    pDato = listaDato;
    int i;
    for(i = 0; i < 2; i++)
    {
        printf("%d - %c\n", (*(pDato + i)).numero, (*(pDato + i)).letra);
    }
    for(i = 0; i < 2; i++)
    {
        printf("%d - %c\n", (pDato + i) -> numero, (pDato + i) -> letra);
    }
    */

    /*
    int* pEntero;
    pEntero = (int *)malloc(sizeof(int));
    *pEntero = 9;
    printf("%d", *pEntero);
    */

    /*
    int* pEntero;
    pEntero = (int *)malloc(sizeof(int)* 5);
    int i;
    for(i = 0; i < 5; i++)
    {
        fflush(stdin);
        scanf("%d", pEntero + i);
        //*(pEntero + i) =  i + 2;
    }
    printf("\nNumeros\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d\n",*(pEntero + i));
    }
    */

    eDato* pDatoUno;
    pDatoUno = funcion(8, 't');
    eDato_mostrar(pDatoUno);
    printf("DATO\n");
    if(pDatoUno != NULL)
    {
        if(eDato_getNumero(pDatoUno, 256))
        {
            printf("OK1\n");
        }
        if(eDato_getLetra(pDatoUno, 'q'))
        {
            printf("OK2\n");
        }
        eDato_mostrar(pDatoUno);
    }
    return 0;
}

eDato* funcion(int numero, char letra)
{
    eDato* pDato;
    pDato = (eDato*) malloc(sizeof(eDato));
    if(pDato != NULL)
    {
        pDato->numero = numero;
        pDato->letra = letra;
    }
    return pDato;
}

int eDato_getNumero(eDato* this, int numero)
{
    if(this != NULL)
    {
        this->numero = numero;
        return 1;
    }
    return 0;
}

int eDato_getLetra(eDato* this, char letra)
{
    if(this != NULL)
    {
        this->letra = letra;
        return 1;
    }
    return 0;
}

int eDato_mostrar(eDato* this)
{
    if(this != NULL)
    {
         printf("%d - %c\n", this->numero, this->letra);
         return 1;
    }
    return 0;
}
