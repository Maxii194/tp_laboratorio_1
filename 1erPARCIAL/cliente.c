#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "aviso.h"
#define QTY 10
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
            strcpy(array[i].apellido,"");
            strcpy(array[i].cuit,"");
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

int cliente_baja2(Cliente* array,Aviso* arrayAvisos,int limiteCliente,int limiteAviso, int id)
{

    int retorno = -1;
    int indice,i;
    char opc;
    indice = cliente_buscarPorId(array,limiteCliente,id);
    printf("\n");
    if(indice >= 0)
    {
        retorno = 0;
        for(i=0;i<limiteAviso;i++){
        	
        	if(indice == arrayAvisos[i].idCliente && arrayAvisos[i].estado == 1){
        		
        		printf("%s - Rubro: %d\n",arrayAvisos[i].textoAviso,arrayAvisos[i].numeroRubro);	
			}
		}
		getOpcion(&opc,"Desea Eliminar el Cliente?[s-n]: ","Error\n",'s','n');
		if(opc == 's'){
    		
    		array[indice].isEmpty = LIBRE;
			for(i=0;i<limiteAviso;i++){
        	
				arrayAvisos[arrayAvisos[indice].idCliente].estado = -1;
			}	
		}
   
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
               printf("\n[RELEASE] %s - %s - %s",array[i].nombre,array[i].apellido,array[i].cuit);
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
            printf("\n[DEBUG] %s - %s - %s - %d - %d",array[i].nombre,array[i].apellido,array[i].cuit,array[i].isEmpty,array[i].idCliente);
        }
    }
    return retorno;
}

int cliente_altaForzada(Cliente* array,int limite,char* nombre,char* apellido, char* cuit)
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
            strcpy(array[i].apellido,apellido);
            strcpy(array[i].cuit,cuit);
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
    char apellido[50];
    char cuit[20];
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
                if(!getValidString("Apellido: ","Error\n","Overflow", apellido,50,2))
                {
                
					for(i=0;i<2;i++){
						
						aux = getStringNumeros("Cuit: ",cuit);
						if(aux==0){
				
							printf("Error\n");
							continue;
						}
						
						retorno = 0;
                        strcpy(array[indice].nombre,nombre);
                        strcpy(array[indice].apellido,apellido);
                        strcpy(array[indice].cuit,cuit);
                        array[indice].idCliente = id;
                        array[indice].isEmpty = OCUPADO;
                        printf("Identificador Cliente: %d\n",array[indice].idCliente);
                        break;
					}
                    
                }
            }
        }
    }
    return retorno;
}


int cliente_modificacion(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int indice;
    char nombre[50];
    char apellido[50];
    char cuit[20];
    int aux,iterador;
    indice = cliente_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = -2;
        if(!getValidString("Nombre?","Error\n","Overflow", nombre,50,2))
        {
            if(!getValidString("Apellido?","Error\n","Overflow", apellido,50,2))
            {
            	for(iterador=0;iterador<2;iterador++){
            		
            		aux = getStringNumeros("Cuit: ",cuit);
            		
            		if(aux==0){
            			
            			printf("Error\n");
						continue;
					}
            		
            		retorno = 0;
                    strcpy(array[indice].nombre,nombre);
                    strcpy(array[indice].apellido,apellido);
                    strcpy(array[indice].cuit,cuit);
                    break;
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

int cliente_mostrarConAvisos(Cliente* array,int limiteClientes,Aviso* arrayAvisos,int limiteAvisos){
	
	int retorno = -1;
    int i;
    int cantidadAvisos = 0;
    if(limiteClientes > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limiteClientes;i++)
        {
            if(!array[i].isEmpty)
            {
            	
    			cantidadAvisos = aviso_contarxId(arrayAvisos,limiteAvisos,i);
            	printf("\nNombre y Apellido Cliente: %s - %s - Cantidad de Avisos: %d",array[i].nombre,array[i].apellido,cantidadAvisos);
            }
        }
    }
    return retorno;
}



