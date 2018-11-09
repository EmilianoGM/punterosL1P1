#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Biblioteca.h"

int pedirEntero(int* pEntero, char mensaje[], char mensajeError[], int minimo, int maximo)
{
    char array[13];
    int numero;
    int error;
    if(pEntero != NULL)
    {
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(array, 13, stdin);
            if(array[(strlen(array) - 1)] != '\n')
            {
                error = 1;
            } else
            {
                /**Devuelve 1 si ES NUMERICA y 0 si NO ES */
                if(comprobarArrayNumericaEntero(array, (strlen(array) - 1)) == 0)
                {
                    error = 1;
                }else
                {
                    array[(strlen(array) - 1)] = '\0';
                    numero = atoi(array);
                    if(numero > maximo || numero < minimo)
                    {
                        error = 1;
                    } else
                    {
                        *pEntero = numero;
                    }
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        } while(error == 1);
        return 0;
    }
    return -1;
}

int pedirStringDeNumeros(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[])
{
    int error;
    char arrayAuxiliar[tamanio + 1];
    int test;
    if(arrayLetras != NULL && tamanio > 0)
    {
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(arrayAuxiliar, (tamanio + 1), stdin);
            if((arrayAuxiliar[(strlen(arrayAuxiliar) - 1)]) != '\n')
            {
                error = 1;
            } else
            {
                arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] = '\0';
                if(comprobarStringNumericoPositivo(arrayAuxiliar, (strlen(arrayAuxiliar) + 1)) != 1)
                {
                    error = 1;
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        }while(error == 1);
        strncpy(arrayLetras, arrayAuxiliar, strlen(arrayAuxiliar) + 1);
        return 0;
    }
    return -1;
}

int pedirStringSoloLetras(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[])
{
    int error;
    int indice;
    char arrayAuxiliar[tamanio + 1];
    if(arrayLetras != NULL && tamanio > 0)
    {
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(arrayAuxiliar, (tamanio + 1), stdin);
            if((arrayAuxiliar[(strlen(arrayAuxiliar) - 1)]) != '\n')
            {
                error = 1;
            } else
            {
                arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] = '\0';
                if(comprobarStringSoloLetras(arrayAuxiliar, strlen(arrayAuxiliar) + 1) != 1)
                {
                    error = 1;
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        }while(error == 1);

        strncpy(arrayLetras, arrayAuxiliar, (strlen(arrayAuxiliar)+ 1));
        return 0;
    }
    return -1;
}

int comprobarStringNumericoPositivo(char cadenaNumerica[], int tamanio)
{
    int retorno = -1;
    int indice;
    if(cadenaNumerica != NULL && tamanio > 0)
    {
        retorno = 1;
        if(strlen(cadenaNumerica) == 0 || strlen(cadenaNumerica) >= tamanio)
        {
            retorno = 0;
        } else
        {
            for(indice = 0; indice < tamanio; indice++)
            {
                if(cadenaNumerica[indice] == '\0')
                {
                    break;
                }
                if(isdigit(cadenaNumerica[indice]) == 0)
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int comprobarArrayNumericaEntero(char cadenaNumerica[], int tamanio)
{
    int retorno = 1;
    int indice = 0;
    if(cadenaNumerica != NULL && tamanio > 0)
    {
        if(cadenaNumerica[0] == '-')
        {
            indice = 1;
        }
        for( ; indice < tamanio; indice++)
        {
            if(isdigit(cadenaNumerica[indice]) == 0)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int comprobarStringSoloLetras(char stringLetras[], int tamanio)
{
    int retorno = -1;
    int indice;
    if(stringLetras != NULL && tamanio > 0)
    {
        retorno = 1;
        if(strlen(stringLetras) == 0 || strlen(stringLetras) >= tamanio)
        {
            retorno = 0;
        } else
        {
            for(indice = 0; indice < tamanio; indice++)
            {
                if(stringLetras[indice] == '\0')
                {
                    break;
                }
                if(isalpha(stringLetras[indice]) == 0)
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

char pedirRespuestaSN(char mensaje[])
{
    char respuesta;
    printf("%s", mensaje);
    do
    {
        fflush(stdin);
        respuesta = getchar();
        respuesta = tolower(respuesta);
        if(respuesta != 's' && respuesta != 'n')
        {
            printf("\nRespuesta invalida. Ingrese s(para si) o n (para no): ");
        }
    } while(respuesta != 's' && respuesta != 'n');
    return respuesta;
}
