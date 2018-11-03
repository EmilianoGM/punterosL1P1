#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Menu.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
      Employee* pEmployee;
      int indice;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pArchivo = fopen(path, "r");
        if(pArchivo != NULL)
        {
            parser_EmployeeFromText(pArchivo, pArrayListEmployee);
            fclose(pArchivo);
              printf("LEN %d", ll_len(pArrayListEmployee));
            return 0;
        }
        for(indice = 0; indice < ll_len(pArrayListEmployee); indice++)
        {
            pEmployee = ll_get(pArrayListEmployee, indice);
            employee_print(pEmployee);
        }
    }
    return -1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    char id[15];
    char nombre[128];
    char horasTrabajadas[15];
    char sueldo[15];
    if(pArrayListEmployee != NULL)
    {
        pedirStringDeNumeros(id, 15, "\nIntroduzca id: ", "\nError id incorrecta. Introduzca Id nuevamente: ");
        pedirStringSoloLetras(nombre, 128, "\nIntroduzca nombre: ", "\nError, nombre invalido. Introduzca nombre nuevamente: ");
        pedirStringDeNumeros(horasTrabajadas, 15, "\nIntroduzca horas trabajadas: ", "\nError, cantidad de horas invalida. Introduzca horas nuevamente: ");
        pedirStringDeNumeros(sueldo, 15, "\nIntroduzca sueldo: ", "\nError, sueldo invalido. Introduzca sueldo nuevamente: ");
        pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
        if(pEmployee != NULL)
        {
            ll_add(pArrayListEmployee, pEmployee);
            employee_print(pEmployee);
            return 0;
        }
    }
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id_aBuscar;
    int id;
    Employee* pEmployee;
    int opcion;
    int indice;
    int flag = 0;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    if(pArrayListEmployee != NULL)
    {
        pedirEntero(&id_aBuscar, "\nIntroduzca el id a buscar: ", "\nError, id invalido. Introduzca el id nuevamente: ", 0, 1000000);
        for(indice = 0; indice < ll_len(pArrayListEmployee); indice++)
        {
            pEmployee = ll_get(pArrayListEmployee, indice);
            employee_getId(pEmployee, &id);
            if(id == id_aBuscar)
            {
                flag = 1;
                printf("\nId encontrado.\n\n");
                break;
            }
        }
        if(flag == 1)
        {
            employee_print(pEmployee);
            printf("\n");
            opcion = menuEditEmployee();
            switch(opcion)
            {
                case 1:
                    pedirStringSoloLetras(nombre, 128, "\nIntroduzca el nuevo nombre: ", "\nError, nombre invalido. Introduzca el nuevo nombre: ");
                    employee_setNombre(pEmployee, nombre);
                    printf("\nNombre modificado.\n");
                    employee_print(pEmployee);
                    break;
                case 2:
                    pedirEntero(&horasTrabajadas, "\nIntroduzca la nueva cantidad de horas trabajadas", "\nError cantidad invalida. Introduzca la cantidad nuevamente: ", 0, 400);
                    employee_setHorasTrabajadas(pEmployee, horasTrabajadas);
                    printf("\nCantidad de horas modificada.\n");
                    employee_print(pEmployee);
                    break;
                case 3:
                    pedirEntero(&sueldo, "\nIntroduzca el nuevo sueldo: ", "\nError, sueldo invalido. Introduzca el sueldo nuevamente: ", 1000, 5000000);
                    employee_setSueldo(pEmployee, sueldo);
                    printf("\nSueldo modificado.\n");
                    employee_print(pEmployee);
                    break;
                case 4:
                    printf("\nEmpleado no modificado.\n");
                    break;
            }
        } else
        {
            printf("\nId no encontrado.\n");
        }
        return 0;
    }
    return -1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id_aBuscar;
    int id;
    Employee* pEmployee;
    char respuesta;
    int indice;
    int flag = 0;
    if(pArrayListEmployee != NULL)
    {
        pedirEntero(&id_aBuscar, "\nIntroduzca el id a buscar: ", "\nError, id invalido. Introduzca el id nuevamente: ", 0, 1000000);
        for(indice = 0; indice < ll_len(pArrayListEmployee); indice++)
        {
            pEmployee = ll_get(pArrayListEmployee, indice);
            employee_getId(pEmployee, &id);
            if(id == id_aBuscar)
            {
                flag = 1;
                printf("\nId encontrado.\n\n");
                break;
            }
        }
        if(flag == 1)
        {
            employee_print(pEmployee);
            respuesta = pedirRespuestaSN("\n¿Desea eliminar empleado?(s para si / n para no):\n");
            if(respuesta == 's')
            {
                ll_remove(pArrayListEmployee, indice);
                printf("\nEmpleado eliminado.\n");
            } else
            {
                printf("\nEmpleado no eliminado.\n");
            }
        } else
        {
            printf("\nId no encontrado.\n");
        }
        return 0;
    }
    return -1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee = NULL;
    int indice;
    if(pArrayListEmployee != NULL)
    {
        for(indice = 0; indice < ll_len(pArrayListEmployee); indice++)
        {
                pEmployee = ll_get(pArrayListEmployee, indice);
                employee_print(pEmployee);
        }
        return 0;
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    if(pArrayListEmployee != NULL)
    {
        opcion = menuSortEmployee();
        switch(opcion)
        {
            case 1:
                printf("\nLista de empleados ordenada por Id(menor a mayor).\n");
                break;
            case 2:
                printf("\nLista de empleados ordenada por Id(mayor a menor).\n");
                break;
            case 3:
                printf("\nLista de empleados ordenada por nombre(A-Z).\n");
                break;
            case 4:
                printf("\nLista de empleados ordenada por nombre(Z-A).\n");
                break;
            case 5:
                printf("\nLista de empleados ordenada por cantidad de horas trabajadas(menor a mayor).\n");
                break;
            case 6:
                printf("\nLista de empleados ordenada por cantidad de horas trabajadas(mayor a menor).\n");
                break;
            case 7:
                printf("\nLista de empleados ordenada por sueldo(menor a mayor).\n");
                break;
            case 8:
                printf("\nLista de empleados ordenada por sueldo(mayor a menor).\n");
                break;
            case 9:
                printf("\nLista no ordenada.\n");
                break;
        }
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

