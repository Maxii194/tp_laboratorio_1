#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#define QTY 20
#define OCUPADO 0
#define LIBRE 1

static int buscarLugarLibre(Cliente* array,int limite);
static int proximoId();

int cliente_init(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            strcpy(array[i].nombre,"");
            array[i].edad = -1;    
            strcpy(array[i].dni,"");
            array[i].idCliente = -1;
            array[i].isEmpty = 1;
        }
    }
    return retorno;
}

int cliente_buscarPorId(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].idCliente == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int cliente_baja(Cliente* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = cliente_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = LIBRE;
    }
    return retorno;
}



int cliente_mostrar(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
               printf("\n[RELEASE] %s - %d - %s",array[i].nombre,array[i].edad,array[i].dni);
            }
        }
    }
    return retorno;
}

int cliente_mostrarDebug(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
        	if(!array[i].isEmpty)
            {
           		printf("\n[DEBUG] %s - %d - %s - %d - %d",array[i].nombre,array[i].edad,array[i].dni,array[i].isEmpty,array[i].idCliente);
        	}
        }
    }
    return retorno;
}

int cliente_altaForzada(Cliente* array,int limite,char* nombre,int edad, char* dni)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            array[i].edad = edad;
            strcpy(array[i].dni,dni);
            //------------------------------
            //------------------------------
            array[i].idCliente = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

int cliente_alta(Cliente* array,int limite)
{
    int retorno = -1;
    char nombre[50];
	int edad;
	char dni[10];
    int id;
    int indice;
    int aux,i;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibre(array,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = proximoId();
            if(!getValidString("Nombre: ","Error\n","Overflow", nombre,50,2))
            {
                if(!getValidInt("Edad: ","\nNumero invalido\n",&edad,0,120,2))
                {
                	
					for(i=0;i<2;i++){
						
					aux = getStringNumeros("DNI: ",dni);
						if(aux<=0){
					
							printf("Error\n");
							continue;
						}
					
						retorno = 0;
	                    strcpy(array[indice].nombre,nombre);
	                    array[indice].edad = edad;
	                    strcpy(array[indice].dni,dni);
	                    array[indice].idCliente = id;
	                    array[indice].isEmpty = OCUPADO;
	                    break;
                    }                          
                }
            }
        }
    }
    return retorno;
}




static int buscarLugarLibre(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}



int cliente_ordenar(Cliente* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Cliente auxiliar;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(array[i].isEmpty == OCUPADO && array[i+1].isEmpty == OCUPADO )
                    {
                        if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && !orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && orden)) //<------------
                        {
                            auxiliar = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return retorno;
}

int cliente_grafico(Cliente* array,int limite){
	
	int retorno = -1;
	
	int i;
	
	printf("\n< 18 \t19-35 \t>35\n");
	
	if(limite > 0 && array != NULL){
		
		retorno = 0;

		
		for(i=0;i<limite;i++){

			if(array[i].isEmpty == OCUPADO){
			
				
				if(array[i].edad < 18){
							
					
					printf("*");
				}
				printf("\t");
				
				if(array[i].edad >= 19 && array[i].edad <= 35){
						
					printf("*");
				}	
				printf("\t");
				
				if(array[i].edad > 35){
						
					printf("*");
				}	
				printf("\n");		
			}
		}
	}
	
	return retorno;
}



