#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "aviso.h"

int informar_clienteConMasAvisosActivos(Cliente* arrayClientes, int limiteClientes,Aviso* arrayAvisos,int limiteAvisos){

	int i,j;
	int contadorAvisosActivos;
	int cantidadAvisosActivosMAX=0;
	int idClienteConMasAvisosActivos;

	for(i=0;i<limiteClientes;i++){

		contadorAvisosActivos = 0;
		for(j=0;j<limiteAvisos;j++){

			if(arrayClientes[i].idCliente == arrayAvisos[j].idCliente && arrayAvisos[j].estado == 1){

				contadorAvisosActivos++;
			}
		}
		if(contadorAvisosActivos > cantidadAvisosActivosMAX){
			cantidadAvisosActivosMAX = contadorAvisosActivos;
			idClienteConMasAvisosActivos = i;
		}
	}

	printf("El cliente con mas Avisos Activos es: %s %s - Cantidad de Avisos Activos: %d",arrayClientes[idClienteConMasAvisosActivos].nombre,arrayClientes[idClienteConMasAvisosActivos].apellido,cantidadAvisosActivosMAX);

	return 0;
}

int informar_clienteConMasAvisosPausados(Cliente* arrayClientes, int limiteClientes,Aviso* arrayAvisos,int limiteAvisos){

	int i,j;
	int contadorAvisosPausados;
	int cantidadAvisosPausadosMAX=0;
	int idClienteConMasAvisosPausados;

	for(i=0;i<limiteClientes;i++){

		contadorAvisosPausados = 0;
		for(j=0;j<limiteAvisos;j++){

			if(arrayClientes[i].idCliente == arrayAvisos[j].idCliente && arrayAvisos[j].estado == 0){

				contadorAvisosPausados++;
			}
		}
		if(contadorAvisosPausados > cantidadAvisosPausadosMAX){
			cantidadAvisosPausadosMAX = contadorAvisosPausados;
			idClienteConMasAvisosPausados = i;
		}
	}
    if(cantidadAvisosPausadosMAX == 0){
        printf("No Hay Avisos Pausados\n");
    }
    else{
        printf("El cliente con mas Avisos Pausados es: %s %s - Cantidad de Avisos Pausados: %d",arrayClientes[idClienteConMasAvisosPausados].nombre,arrayClientes[idClienteConMasAvisosPausados].apellido,cantidadAvisosPausadosMAX);
    }

	return 0;
}

int informar_clienteConMasAvisos(Cliente* arrayClientes, int limiteClientes,Aviso* arrayAvisos,int limiteAvisos){

	int i,j;
	int contadorAvisos;
	int cantidadAvisosMAX=0;
	int idClienteConMasAvisos;

	for(i=0;i<limiteClientes;i++){

		contadorAvisos = 0;
		for(j=0;j<limiteAvisos;j++){

			if(arrayClientes[i].idCliente == arrayAvisos[j].idCliente && arrayAvisos[j].estado != -1){

				contadorAvisos++;
			}
		}
		if(contadorAvisos > cantidadAvisosMAX){
			cantidadAvisosMAX = contadorAvisos;
			idClienteConMasAvisos = i;
		}
	}

	printf("El cliente con mas Avisos es: %s %s - Cantidad de Avisos: %d",arrayClientes[idClienteConMasAvisos].nombre,arrayClientes[idClienteConMasAvisos].apellido,cantidadAvisosMAX);

	return 0;
}

int informar_cantidadDePublicacionesXrubro(Aviso* arrayAvisos,int limiteAvisos){


	int i;
	int rubroAbuscar;
	int contadorRubro=0;

	if(!getValidInt("Ingrese Rubro: ","Error\n",&rubroAbuscar,0,100,2)){

		for(i=0;i<limiteAvisos;i++){

			if(arrayAvisos[i].numeroRubro == rubroAbuscar && arrayAvisos[i].estado == 1){

				contadorRubro++;
			}
		}
		printf("Rubro %d: %d Publicaciones\n",rubroAbuscar,contadorRubro);
		return 0;
	}

	return -1;
}

int informar_rubroConMasPublicaciones(Aviso* arrayAvisos,int limiteAvisos){


	int i,j;
	int contadorRubroConMasPublicacionesActivas;
	int contadorRubroConMasPublicacionesActivasMAX=0;
	int idAvisoConMasPublicacionesActivas;

	for(j=0;j<limiteAvisos;j++){

		contadorRubroConMasPublicacionesActivas=0;

		for(i=0;i<limiteAvisos;i++)
		{
			if(arrayAvisos[j].numeroRubro == arrayAvisos[i].numeroRubro && arrayAvisos[i].estado == 1){

				contadorRubroConMasPublicacionesActivas++;
			}
				if(contadorRubroConMasPublicacionesActivas > contadorRubroConMasPublicacionesActivasMAX){
				contadorRubroConMasPublicacionesActivasMAX = contadorRubroConMasPublicacionesActivas;
				idAvisoConMasPublicacionesActivas = j;
			}
		}
	}

	printf("El rubro con mas publicaciones Activas es: Rubro %d",arrayAvisos[idAvisoConMasPublicacionesActivas].numeroRubro);

	return 0;
}

int informar_rubroConMenosPublicaciones(Aviso* arrayAvisos,int limiteAvisos){


	int i,j;
	int contadorRubroConMenosPublicacionesActivas;
	int contadorRubroConMenosPublicacionesActivasMIN=1001;
	int idAvisoConMenosPublicaciones;

	for(j=0;j<limiteAvisos;j++){

		contadorRubroConMenosPublicacionesActivas=0;

		for(i=0;i<limiteAvisos;i++)
		{
			if(arrayAvisos[j].numeroRubro == arrayAvisos[i].numeroRubro && arrayAvisos[i].estado == 1){

				contadorRubroConMenosPublicacionesActivas++;
			}
		}

        if(contadorRubroConMenosPublicacionesActivas < contadorRubroConMenosPublicacionesActivasMIN && arrayAvisos[j].estado == 1){
            contadorRubroConMenosPublicacionesActivasMIN = contadorRubroConMenosPublicacionesActivas;
            idAvisoConMenosPublicaciones = j;
        }
	}

	printf("El rubro con menos publicaciones Activas es: Rubro %d",arrayAvisos[idAvisoConMenosPublicaciones].numeroRubro);

	return 0;
}
