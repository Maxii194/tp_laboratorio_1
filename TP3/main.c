#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"

void mostrarPeliculas(EMovie* array[],int cantidad);
void cargarPeliculas(EMovie** array,int *cantidad);
void eliminarPelicula(EMovie* array[],int *cantidad,char *pelicula);


int main()
{
    //char seguir='s';
    //int opcion=0;

    EMovie* pArrayPeliculas[5];
    int qtyActualArrayPeliculas = 0;
    //int qtyMaximaArrayPeliculas = 5;

    pArrayPeliculas[qtyActualArrayPeliculas] = movie_newParametros("Inception","Ciencia Ficcion",3," 404 ",10," 404 ");
    qtyActualArrayPeliculas++;
    pArrayPeliculas[qtyActualArrayPeliculas] = movie_newParametros("Banieros","Comedia",3," 404 ",10," 404 ");
    qtyActualArrayPeliculas++;
    pArrayPeliculas[qtyActualArrayPeliculas] = movie_newParametros("Titanic","Drama",3," 404 ",10," 404 ");
    qtyActualArrayPeliculas++;
    pArrayPeliculas[qtyActualArrayPeliculas] = movie_newParametros("Taken","Accion",3," 404 ",10," 404 ");
    qtyActualArrayPeliculas++;


    cargarPeliculas(pArrayPeliculas,&qtyActualArrayPeliculas);
    printf("%d\n",qtyActualArrayPeliculas);
    eliminarPelicula(pArrayPeliculas,&qtyActualArrayPeliculas,"Banieros");
    qtyActualArrayPeliculas--;
    printf("%d\n",qtyActualArrayPeliculas);
    mostrarPeliculas(pArrayPeliculas,qtyActualArrayPeliculas);


    /*while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                cargarPeliculas(pArrayPeliculas,&qtyActualArrayPeliculas);
                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }*/

    return 0;
}

void mostrarPeliculas(EMovie* array[],int cantidad)
{
    int i;
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[200];

    for(i=0 ; i<cantidad;i++)
    {
        if(array[i] != NULL){

            movie_getTitulo(array[i],titulo);
            movie_getGenero(array[i],genero);
            movie_getDuracion(array[i],&duracion);
            movie_getDescripcion(array[i],descripcion);
            movie_getPuntaje(array[i],&puntaje);
            movie_getLinkImagen(array[i],linkImagen);

            printf("%s - %s - %d - %s - %d - %s - %d\n",titulo,genero,duracion,descripcion,puntaje,linkImagen,i);
        }
    }
}

void cargarPeliculas(EMovie* array[],int* cantidad){

    char titulo[50];
    char genero[50];
    float duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[200];

    if((*cantidad) > 0 && array != NULL)
    {
        if(!getValidAlfaNumerico("Titulo: ","Error\n","Overflow", titulo,50,2))
        {
            if(!getValidString("Genero: ","Error\n","Overflow", genero,50,2))
            {
                if(!getValidFloat("Duracion: ","Error",&duracion,0,5,2))
                {
                    if(!getValidAlfaNumerico("Descripcion: ","Error\n","Overflow", descripcion,50,2))
                    {
                        if(!getValidInt("Puntaje: ","Error\n",&puntaje,0,10,2))
                        {
                            if(!getValidStringAllCharacters("Link de Imagen: ","Error\n","Overflow", linkImagen,50,2))
                            {
                                array[*cantidad] = movie_newParametros(titulo,genero,duracion,descripcion,puntaje,linkImagen);
                                (*cantidad)++;
                            }
                        }
                    }
                }
            }
        }
    }
}

void eliminarPelicula(EMovie* array[],int *cantidad,char *pelicula){

    int i,j;
    int comp;

    if(array != NULL){

        for(i=0;i<*cantidad;i++){
            comp = strcmp(pelicula,array[i]->titulo);
            if(comp == 0){
                printf("%s %s %d\n",array[i]->titulo,pelicula,i);
                array[i]= NULL;
                for(j=i;j<*cantidad-1;j++){

                    array[j] = array[j+1];
                }
                break;
            }
            else if(i==*cantidad-1){
                printf("Pelicula no encontrada\n");
            }
        }
    }
}
