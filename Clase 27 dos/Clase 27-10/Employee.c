#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new(void)
{
    Employee* pEmployee = NULL;
    pEmployee = (Employee *) malloc(sizeof(Employee));
    return pEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* pEmployee = NULL;
    int id;
    int horasTrabajadas;
    int sueldo;
    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        pEmployee = employee_new();
        if(pEmployee != NULL)
        {
            id = atoi(idStr);
            horasTrabajadas = atoi(horasTrabajadasStr);
            sueldo = atoi(sueldoStr);
            employee_setId(pEmployee, id);
            employee_setNombre(pEmployee, nombreStr);
            employee_setHorasTrabajadas(pEmployee, horasTrabajadas);
            employee_setSueldo(pEmployee, sueldo);
        }

    }
    return pEmployee;
}

int employee_setId(Employee* this,int id)
{
    if(this != NULL)
    {
        this->id = id;
        return 0;
    }
    return -1;
}

int employee_getId(Employee* this,int* id)
{
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        return 0;
    }
    return -1;
}

int employee_setNombre(Employee* this,char* nombre)
{
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        return 0;
    }
    return -1;
}

int employee_getNombre(Employee* this,char* nombre)
{
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        return 0;
    }
    return -1;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        return 0;
    }
    return -1;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        return 0;
    }
    return -1;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    if(this != NULL)
    {
        this->sueldo = sueldo;
        return 0;
    }
    return -1;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        return 0;
    }
    return -1;
}

int employee_print(Employee* this)
{
    if(this != NULL)
    {
        printf("%5d | %15s | %4d | %6d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        return 0;
    }
    return -1;
}

int employee_compareId(void* this, void* thisDos)
{
    int retorno;
    Employee* pEmployee = NULL;
    Employee* pEmployeeDos = NULL;
    if(this != NULL && thisDos != NULL)
    {
        pEmployee = (Employee*)this;
        pEmployeeDos = (Employee*)thisDos;
        if(pEmployee->id > pEmployeeDos->id)
        {
            retorno = 1;
        } else if(pEmployee->id < pEmployeeDos->id)
        {
            retorno = -1;
        } else
        {
            retorno = 0;
        }

    }
    return retorno;
}

int employee_compareNombre(void* this, void* thisDos)
{
    int retorno;
    Employee* pEmployee = NULL;
    Employee* pEmployeeDos = NULL;
    if(this != NULL && thisDos != NULL)
    {
        pEmployee = (Employee*)this;
        pEmployeeDos = (Employee*)thisDos;
        retorno = strcmp(pEmployee->nombre, pEmployeeDos->nombre);
    }
    return retorno;

}

int employee_compareHorasTrabajadas(void* this, void* thisDos)
{
    int retorno;
    Employee* pEmployee = NULL;
    Employee* pEmployeeDos = NULL;
    if(this != NULL && thisDos != NULL)
    {
        pEmployee = (Employee*)this;
        pEmployeeDos = (Employee*)thisDos;
        if(pEmployee->horasTrabajadas > pEmployeeDos->horasTrabajadas)
        {
            retorno = 1;
        } else if(pEmployee->horasTrabajadas < pEmployeeDos->horasTrabajadas)
        {
            retorno = -1;
        } else
        {
            retorno = 0;
        }

    }
    return retorno;
}

int employee_compareSueldo(void* this, void* thisDos)
{
    int retorno;
    Employee* pEmployee = NULL;
    Employee* pEmployeeDos = NULL;
    if(this != NULL && thisDos != NULL)
    {
        pEmployee = (Employee*)this;
        pEmployeeDos = (Employee*)thisDos;
        if(pEmployee->sueldo > pEmployeeDos->sueldo)
        {
            retorno = 1;
        } else if(pEmployee->sueldo < pEmployeeDos->sueldo)
        {
            retorno = -1;
        } else
        {
            retorno = 0;
        }

    }
    return retorno;
}
