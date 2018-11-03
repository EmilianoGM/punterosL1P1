#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int id;
    char nombre[128];
    int sueldo;
}Employee;

int main()
{
    FILE* pArchivo = NULL;
    Employee* pEmployeeDos;
    Employee* pEmployee[5];
    int indice = 0;
    pArchivo = fopen("dataprueba.csv", "rb");

    if(pArchivo == NULL)
    {
        printf("NULL\n");
    } else
    {
        printf("OK\n");
    }
    for(indice = 0; indice < 5; indice++)
    {
        pEmployee[indice] = (Employee *) malloc(sizeof(Employee));
    }
    indice = 0;
    pEmployeeDos = (Employee *) malloc(sizeof(Employee));
    int cant;
    cant=fread(pEmployeeDos,sizeof(Employee),1,pArchivo);
    printf("%5d | %15s | %6d",pEmployeeDos->id, pEmployeeDos->nombre, pEmployeeDos->sueldo);
    /*
    while(!feof(pArchivo))
    {
        cantidad = fread(pEmployee[indice], sizeof(Employee), 1, pArchivo);
        indice++;
    }
    fclose(pArchivo);
    printf("CANTIDAD %d", cantidad);
    */
    /*
    int cant;
    while(!feof(pArchivo))
    {
        cant=fread(pEmployee[indice],sizeof(Employee),1,pArchivo);
        indice++;
        if(cant!=1)
        {
            if(feof(pArchivo))
            {
                printf("LEYO OK\n");
                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
    }
    */
    fclose(pArchivo);
    /*
    for(indice = 0; indice < 5; indice++)
    {
        printf("%5d | %15s | %6d", pEmployee[indice]->id, pEmployee[indice]->nombre, pEmployee[indice]->sueldo);
    }
    */
    return 0;
}
