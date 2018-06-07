#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"

#define QTY 20


int main()
{
    Cliente arrayClientes[QTY];

    int menu;
    int auxiliarId;
    int validaPausa;
    int a;

    cliente_init(arrayClientes,QTY);



   cliente_altaForzada(arrayClientes,QTY,"Pablo",22,"30287891");
   cliente_altaForzada(arrayClientes,QTY,"Ana",45,"30287891");
   cliente_altaForzada(arrayClientes,QTY,"Sebastian",10,"30287891");
   cliente_altaForzada(arrayClientes,QTY,"Mauricio",55,"30287891");

    char seguir='s';
    int opcion=0;

    do
    {	
        printf("\n\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            	cliente_alta(arrayClientes,QTY);
                break;
            case 2:
            	getValidInt("ID: ","\nNumero invalido\n",&auxiliarId,0,200,2);
            	cliente_baja(arrayClientes,QTY, auxiliarId);
                break;
            case 3:
            	cliente_ordenar(arrayClientes,QTY,1);
            	cliente_mostrarDebug(arrayClientes,QTY);
                break;
            case 4:
            	cliente_grafico(arrayClientes,QTY);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }while(seguir!=6);
    return 0;
}
