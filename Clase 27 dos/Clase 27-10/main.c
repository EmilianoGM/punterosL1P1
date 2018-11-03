#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menu.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int archivoDataCargado = 0;
    do
    {
        opcion = menuPrincipal();
        system("cls");
        switch(opcion)
        {
            case 1:
                if(archivoDataCargado == 0)
                {
                    controller_loadFromText("data.csv", listaEmpleados);
                    archivoDataCargado = 1;
                } else
                {
                    printf("El archivo ya a sido cargado.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 2:
                if(archivoDataCargado == 0)
                {
                    controller_loadFromBinary("dataUno.bin", listaEmpleados);
                    archivoDataCargado = 1;
                } else
                {
                    printf("El archivo ya a sido cargado.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 3:
                if(archivoDataCargado == 1)
                {
                    controller_addEmployee(listaEmpleados);
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 4:
                if(archivoDataCargado == 1)
                {
                    controller_editEmployee(listaEmpleados);
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 5:
                if(archivoDataCargado == 1)
                {
                    controller_removeEmployee(listaEmpleados);
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 6:
                if(archivoDataCargado == 1)
                {
                    controller_ListEmployee(listaEmpleados);
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 7:
                if(archivoDataCargado == 1)
                {
                    controller_sortEmployee(listaEmpleados);
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 8:
                if(archivoDataCargado == 1)
                {
                    controller_saveAsText("dataUno.csv", listaEmpleados);
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 9:
                if(archivoDataCargado == 1)
                {
                    controller_saveAsBinary("dataUno.bin", listaEmpleados);
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 10:
                break;
        }
    }while(opcion != 10);

    printf("Gracias por usar la aplicacion\n");

    return 0;
}
