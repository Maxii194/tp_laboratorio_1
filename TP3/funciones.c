#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "funciones.h"
#include "html.h"


EMovie* movie_newParametros(char* titulo,char* genero,int duracion, char* descripcion, int puntaje, char* linkImagen)
{
    EMovie* auxMovie = movie_new();

    if(     !movie_setTitulo(auxMovie, titulo)
       &&   !movie_setGenero(auxMovie, genero)
       &&   !movie_setDuracion(auxMovie, duracion)
       &&   !movie_setDescripcion(auxMovie,descripcion)
       &&   !movie_setPuntaje(auxMovie, puntaje)
       &&   !movie_setLinkImagen(auxMovie, linkImagen))
    {
         return auxMovie;
    }
    movie_delete(auxMovie);
    return NULL;
}

EMovie* movie_new()
{
    return malloc(sizeof(EMovie));
}

void movie_delete(EMovie* this)
{
    free(this);
}

int  movie_setDuracion(EMovie* this, int duracion)
{
    int retorno = -1;
    if(this != NULL && duracion >= 0)
    {

        this->duracion = duracion;
        retorno = 0;
    }
    return retorno;
}

int movie_getDuracion(EMovie* this, int* duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {

        *duracion = this->duracion;
        retorno = 0;
    }
    return retorno;

}

char  movie_setTitulo(EMovie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {

        strcpy(this->titulo,titulo);
        retorno = 0;
    }
    return retorno;
}

char movie_getTitulo(EMovie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {

        strcpy(titulo,this->titulo);
         retorno = 0;
    }
    return retorno;
}

char  movie_setDescripcion(EMovie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {

        strcpy(this->descripcion,descripcion);
        retorno = 0;
    }
    return retorno;
}

char movie_getDescripcion(EMovie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {

        strcpy(descripcion,this->descripcion);
         retorno = 0;
    }
    return retorno;
}

char  movie_setGenero(EMovie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {

        strcpy(this->genero,genero);
        retorno = 0;
    }
    return retorno;
}

char movie_getGenero(EMovie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {

        strcpy(genero,this->genero);
        retorno = 0;
    }
    return retorno;
}

int  movie_setPuntaje(EMovie* this, int puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje >= 0)
    {

        this->puntaje = puntaje;
        retorno = 0;
    }
    return retorno;
}

int movie_getPuntaje(EMovie* this, int* puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje != NULL)
    {

        *puntaje = this->puntaje;
        retorno = 0;
    }
    return retorno;

}

char  movie_setLinkImagen(EMovie* this, char* linkImagen)
{
    int retorno = -1;
    if(this != NULL && linkImagen != NULL)
    {

        strcpy(this->linkImagen,linkImagen);
        retorno = 0;
    }
    return retorno;
}

char movie_getLinkImagen(EMovie* this, char* linkImagen)
{
    int retorno = -1;
    if(this != NULL && linkImagen != NULL)
    {

        strcpy(linkImagen,this->linkImagen);
         retorno = 0;
    }
    return retorno;
}

void mostrarPeliculas(EMovie* this[],int cantidad)
{
    int i;
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[500];

    for(i=0 ; i<cantidad;i++)
    {
        if(this[i] != NULL){

            movie_getTitulo(this[i],titulo);
            movie_getGenero(this[i],genero);
            movie_getDuracion(this[i],&duracion);
            movie_getDescripcion(this[i],descripcion);
            movie_getPuntaje(this[i],&puntaje);
            movie_getLinkImagen(this[i],linkImagen);

            printf("%s - %s - %d - %s - %d - %s - %d\n",titulo,genero,duracion,descripcion,puntaje,linkImagen,i);
        }
    }
}

/**
 *  Agrega una movie al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la movie o no
 */
void cargarPeliculas(EMovie* this[],int* cantidad){

    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[500];

    if((*cantidad) > 0 && this != NULL)
    {
        if(!getValidAlfaNumerico("Titulo: ","Error\n","Overflow", titulo,50,2))
        {
            if(!getValidString("Genero: ","Error\n","Overflow", genero,50,2))
            {
                if(!getValidInt("Duracion: ","Error",&duracion,0,500,2))
                {
                    if(!getValidAlfaNumerico("Descripcion: ","Error\n","Overflow", descripcion,50,2))
                    {
                        if(!getValidInt("Puntaje: ","Error\n",&puntaje,0,100,2))
                        {
                            if(!getValidStringAllCharacters("Link de Imagen: ","Error\n","Overflow", linkImagen,50,2))
                            {
                                this[*cantidad] = movie_newParametros(titulo,genero,duracion,descripcion,puntaje,linkImagen);
                                (*cantidad)++;
                            }
                        }
                    }
                }
            }
        }
    }
}

/**
 *  Borra una movie del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la movie o no
 */
void eliminarPelicula(EMovie* this[],int *cantidad,char *pelicula){

    int i,j;
    int comp;

    if(this != NULL){

        for(i=0;i<*cantidad;i++){
            comp = strcmp(pelicula,this[i]->titulo);
            if(comp == 0){

                this[i]= NULL;
                for(j=i;j<*cantidad-1;j++){

                    this[j] = this[j+1];
                }
                break;
            }
            else if(i==*cantidad-1){
                printf("Pelicula no encontrada\n");
            }
        }
    }
}

int generarPagina(EMovie* this[], int cantidad, int pelicula,char* path)
{
    int retorno = -1;

    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[500];

    FILE* pFile;
    pFile = fopen(path,"a");
    if(pFile != NULL && this != NULL)
    {

        movie_getTitulo(this[pelicula],titulo);
        movie_getGenero(this[pelicula],genero);
        movie_getDuracion(this[pelicula],&duracion);
        movie_getDescripcion(this[pelicula],descripcion);
        movie_getPuntaje(this[pelicula],&puntaje);
        movie_getLinkImagen(this[pelicula],linkImagen);

        html_primerInstancia(path,pFile);
        fprintf(pFile,"%s",linkImagen);
        html_segundaInstancia(path,pFile);
        fprintf(pFile,"%s",titulo);
        html_terceraInstancia(path,pFile);
        fprintf(pFile,"%s",genero);
        html_cuartaInstancia(path,pFile);
        fprintf(pFile,"%d",puntaje);
        html_quintaInstancia(path,pFile);
        fprintf(pFile,"%d",duracion);
        html_sextaInstancia(path,pFile);
        fprintf(pFile,"%s",descripcion);
        html_septimaInstancia(path,pFile);
    }
    fclose(pFile);

    return retorno;
}

int movie_buscarPelicula(EMovie* this[], int cantidad, char* pelicula){

    int retorno = -1;
    int i;

    for(i=0;i<cantidad;i++){

        if(strcmp(this[i]->titulo,pelicula)==0){

            retorno = 0;
        }
    }

    return retorno;
}

int movie_buscarIndexPelicula(EMovie* this[], int cantidad, char* pelicula){

    int retorno = -1;
    int i;

    for(i=0;i<cantidad;i++){

        if(strcmp(this[i]->titulo,pelicula)==0){

            retorno = i;
            return retorno;
        }
    }

    return retorno;
}
