#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numero;
    char letra;
}eDato;

eDato* funcion(int numero, char letra);

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
    return 0;
}

eDato* funcion(int numero, char letra)
{
    eDato* pDato;
    eDato datoUno;
    pDato = &datoUno;
    pDato->numero = numero;
    pDato->letra = letra;

    return pDato;
}
