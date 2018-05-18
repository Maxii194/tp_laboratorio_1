#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "aviso.h"
#include "utn.h"
#include "informar.h"
#define QTY 100
#define LEN_AVISOS 1000

int main()
{
    Cliente arrayClientes[QTY];
    Aviso arrayAvisos[LEN_AVISOS];
    int menu;
    int auxiliarId;
    int validaMod;
    int validaPausa;
    int validaBajaCliente,validaReanudar;

    cliente_init(arrayClientes,QTY);
    aviso_init(arrayAvisos,LEN_AVISOS);


   cliente_altaForzada(arrayClientes,QTY,"Pablo","Belgrano","20132135");
   cliente_altaForzada(arrayClientes,QTY,"Augusto","Capa","20102030");
   cliente_altaForzada(arrayClientes,QTY,"Belen","Alberti","20153135");

   aviso_altaForzada(arrayAvisos,LEN_AVISOS,"HOLA_MUNDO",60,2);
   aviso_altaForzada(arrayAvisos,LEN_AVISOS,"Standtlic",60,2);
   aviso_altaForzada(arrayAvisos,LEN_AVISOS,"ALGO",60,2);
   aviso_altaForzada(arrayAvisos,LEN_AVISOS,"YO",60,2);
   aviso_altaForzada(arrayAvisos,LEN_AVISOS,"QUETAL",60,2);
   aviso_altaForzada(arrayAvisos,LEN_AVISOS,"Libertadores",10,0);
   aviso_altaForzada(arrayAvisos,LEN_AVISOS,"Sudamericana",22,1);
   aviso_altaForzada(arrayAvisos,LEN_AVISOS,"UEFA",22,1);
   aviso_altaForzada(arrayAvisos,LEN_AVISOS,"AAAAA",10,0);
   aviso_altaForzada(arrayAvisos,LEN_AVISOS,"BBBBB",10,0);
   aviso_altaForzada(arrayAvisos,LEN_AVISOS,"CCCCC",10,0);


    do
    {
        getValidInt("\n\n1.Alta Cliente\n2.Modificar\n3.Eliminar Cliente\n4.Publicar Aviso\n5.Pausar Publicacion\n6.Reanudar Publicacion\n7.Imprimir Clientes\n8.Imprimir Publicaciones\n9.Clientes Con Mas Avisos Activos\n10.Clientes Con Mas Avisos Pausados\n11.Clientes Con Mas Avisos\n12.Cantidad De Publicaciones de un Rubro\n13.Rubro con mas Publicaciones Activas\n14.Rubro con menos Publicaciones Activas\n15.Salir\n\n","\nNo valida\n",&menu,1,14,1);
        switch(menu)
        {
            case 1:
                cliente_alta(arrayClientes,QTY);
                break;
            case 2:
            	validaMod = getValidInt("ID: ","\nNumero invalido\n",&auxiliarId,0,200,2);
                if(validaMod == 0){
                	cliente_modificacion(arrayClientes,QTY,auxiliarId);
				}
                break;
            case 3:
                validaBajaCliente = getValidInt("ID: ","\nNumero invalido\n",&auxiliarId,0,200,2);
                if(validaBajaCliente == 0){
                    cliente_baja2(arrayClientes,arrayAvisos,QTY,LEN_AVISOS,auxiliarId);
                }
                break;
            case 4:
            	getValidInt("ID: ","\nNumero invalido\n",&auxiliarId,0,200,2);
                aviso_alta(arrayAvisos,arrayClientes,QTY,LEN_AVISOS);
                break;
            case 5:
            	validaPausa = getValidInt("ID: ","\nNumero invalido\n",&auxiliarId,0,200,2);
                if(validaPausa == 0){
                	aviso_pausar(arrayAvisos,arrayClientes,LEN_AVISOS,QTY,auxiliarId);
                }
                break;
            case 6:
                validaReanudar = getValidInt("ID: ","\nNumero invalido\n",&auxiliarId,0,200,2);
                if(validaReanudar == 0){
                    aviso_reaunadar(arrayAvisos,arrayClientes,LEN_AVISOS,QTY,auxiliarId);
                }
                break;
            case 7:
				cliente_mostrarConAvisos(arrayClientes,QTY,arrayAvisos,LEN_AVISOS);
				break;
            case 8:
            	aviso_mostrarAvisoConCuit(arrayAvisos,LEN_AVISOS,arrayClientes);
				break;
            case 9:
                informar_clienteConMasAvisosActivos(arrayClientes,QTY,arrayAvisos,LEN_AVISOS);
				break;
            case 10:
				informar_clienteConMasAvisosPausados(arrayClientes,QTY,arrayAvisos,LEN_AVISOS);
				break;
            case 11:
				informar_clienteConMasAvisos(arrayClientes,QTY,arrayAvisos,LEN_AVISOS);
				break;
			case 12:
				informar_cantidadDePublicacionesXrubro(arrayAvisos,LEN_AVISOS);
				break;
			case 13:
				informar_rubroConMasPublicaciones(arrayAvisos,LEN_AVISOS);
				break;
            case 14:
				informar_rubroConMenosPublicaciones(arrayAvisos,LEN_AVISOS);
				break;
        }
    }while(menu != 15);

    return 0;
}
