#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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

typedef struct
{
    int numero;
    char letra;
}eDato;


int main()
{
    //int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    eDato* datoUno = (eDato *) malloc(sizeof(eDato));
    eDato* datoDos = (eDato *) malloc(sizeof(eDato));
    eDato* datoTres = (eDato *) malloc(sizeof(eDato));
    eDato* datoCuatro = (eDato *) malloc(sizeof(eDato));

    datoUno->numero = 7;
    datoUno->letra = 'A';
    datoDos->numero = 1;
    datoDos->letra = 'J';
    datoTres->numero = 6;
    datoTres->letra = 'U';
    datoCuatro->numero = 3;
    datoCuatro->letra = 'K';

    ll_add(listaEmpleados, datoUno);
    ll_add(listaEmpleados, datoDos);
    ll_add(listaEmpleados, datoTres);
    ll_add(listaEmpleados, datoCuatro);

    int len

    /*
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);
    */
    return 0;
}
