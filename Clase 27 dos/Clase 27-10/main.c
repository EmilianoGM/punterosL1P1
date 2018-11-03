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
    do
    {
        opcion = menuPrincipal();
        system("cls");
        switch(opcion)
        {
            case 1:
                controller_loadFromText("data.csv", listaEmpleados);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 2:
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
        }
    }while(opcion != 10);

    printf("Gracias por usar la aplicacion\n");

    return 0;
}
