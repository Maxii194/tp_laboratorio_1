#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aviso.h"
#include "utn.h"
#include "cliente.h"
#define QTY 10
#define LEN_AVISOS 10
#define OCUPADO 0
#define LIBRE 1
#define PAUSADA 0
#define ACTIVA 1
#define NO_ACTIVA -1


static int buscarLugarLibre(Aviso* array,int limite);
static int proximoId();

int aviso_init(Aviso* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            strcpy(array[i].textoAviso,"");
            array[i].numeroRubro = -1;
            array[i].idAviso = '\0';
            array[i].idCliente = -1;
            array[i].estado = NO_ACTIVA;
        }
    }
    return retorno;
}

int aviso_buscarPorId(Aviso* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].estado == ACTIVA && array[i].idAviso == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int verificariId_Aviso(Aviso* array,int id, int limite){
	
	int i;
	
	for(i=0;i<limite;i++){
			
		if(id == array[i].idAviso){
				
			return 0;
		}
	}
	
	return -1;
}

int aviso_pausar(Aviso* array,Cliente* arrayClientes,int limite,int limiteClientes, int id)
{

    int retorno = -1;
    char opc;
    if(!verificariId_Aviso(array,id, limite)){

    	retorno = 0;
    	printf("La publicacion pertenece a:\n");
    	printf("\tNombre y Apellido Cliente: %s %s\tCuit: %s\n",arrayClientes[array[id].idCliente].nombre,arrayClientes[array[id].idCliente].apellido,arrayClientes[array[id].idCliente].cuit);
    	getOpcion(&opc,"Desea Pausar el Aviso?[s-n]: ","Error\n",'s','n');
    	if(opc == 's'){
    		
    		array[id].estado = PAUSADA;
		}
	}
    return retorno;
}

int aviso_reaunadar(Aviso* array,Cliente* arrayClientes,int limite,int limiteClientes, int id)
{

    int retorno = -1;
    char opc;
    if(!verificariId_Aviso(array,id, limite)){
    	printf("%d",id);
    	retorno = 0;
    	printf("La publicacion pertenece a:\n");
    	printf("\tNombre y Apellido Cliente: %s %s\tCuit: %s\n",arrayClientes[array[id].idCliente].nombre,arrayClientes[array[id].idCliente].apellido,arrayClientes[array[id].idCliente].cuit);
    	getOpcion(&opc,"Desea Reanudar el Aviso?[s-n]: ","Error\n",'s','n');
    	if(opc == 's'){
    		
    		array[id].estado = ACTIVA;
		}
	}
    return retorno;
}

int aviso_mostrar(Aviso* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(array[i].estado == ACTIVA)
            {
              	printf("\n[RELEASE] %s - %d",array[i].textoAviso,array[i].numeroRubro);
            }
        }
    }
    return retorno;
}

int aviso_mostrarDebug(Aviso* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("\n[DEBUG] %s - %d - %d - %d - %d",array[i].textoAviso,array[i].numeroRubro,array[i].idAviso,array[i].idCliente,array[i].estado);
        }
    }
    return retorno;
}


int aviso_alta(Aviso* array,Cliente* arrayClientes,int limiteClientes, int limite)
{
    int retorno = -1;
    char textoAviso[64];
    int numeroRubro;
    int id;
    int indice;
    int aux;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibre(array,limite);
        if(indice >= 0)
        {
            retorno = -3;

            if(!verificariId_Aviso_Cliente(arrayClientes,id,limiteClientes)){
				
			
                if(!getValidInt("Numero Rubro: ","\nNumero invalido\n",&numeroRubro,0,100,2))
                {
                    if(!getValidString("Texto Aviso: ","Error","Overflow", textoAviso,64,2)){
						
                        retorno = 0;
                        strcpy(array[indice].textoAviso,textoAviso);
                        array[indice].numeroRubro = numeroRubro;
                        array[indice].idAviso = indice;
                        array[indice].idCliente = id;
                        array[indice].estado = ACTIVA;
                        printf("Identificador Aviso: %d\n",indice);
                    }
                }
            }
        }
    }
    return retorno;
}


int verificariId_Aviso_Cliente(Cliente* arrayClientes,int id, int limiteClientes){
	
	int i;
	
	for(i=0;i<limiteClientes;i++){
			
		if(id == arrayClientes[i].idCliente){
				
			return 0;
		}
	}
	
	return -1;
}

static int buscarLugarLibre(Aviso* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].estado == NO_ACTIVA)
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


int aviso_altaForzada(Aviso* array,int limite,char* textoAviso,int numeroRubro, int id)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].textoAviso,textoAviso);
            array[i].numeroRubro = numeroRubro;
            //------------------------------
            //------------------------------
            array[i].idAviso = proximoId();
            array[i].idCliente = id;
            array[i].estado = ACTIVA;
        }
        retorno = 0;
    }
    return retorno;
}

int aviso_contarxId(Aviso* array,int limite, int id){
	
	int i;
	int contador=0;
	
	for(i=0;i<limite;i++){
		
		if(array[i].idCliente == id && array[i].estado == ACTIVA){
			
			contador++;
		}
	}
	return contador;
}

int aviso_mostrarAvisoConCuit(Aviso* array,int limite,Cliente* arrayClientes)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(array[i].estado == ACTIVA)
            {
               printf("\n%s - Rubro: %d Cuit Cliente: %s",array[i].textoAviso,array[i].numeroRubro,arrayClientes[(array[i].idCliente)].cuit);
            }
        }
    }
    return retorno;
}



