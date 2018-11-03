#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* pEmployee = NULL;
    int cantidadDeDatosLeidos;
    char id[15];
    char nombre[128];
    char horasTrabajadas[15];
    char sueldo[15];
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            cantidadDeDatosLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
            if(cantidadDeDatosLeidos == 4 && isdigit(id[0]) != 0)
            {
                pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
                if(pEmployee != NULL)
                {
                    employee_print(pEmployee);
                    ll_add(pArrayListEmployee, pEmployee);
                }
            }

        }
        return 0;
    }
    return -1;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
