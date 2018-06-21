#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "funciones.h"

//static int buscarLugarLibre(EMovie* array,int limite);
//static int proximoId();

/**
 *  Agrega una movie al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la movie o no
 */
int agregarPelicula(EMovie movie);

/**
 *  Borra una movie del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la movie o no
 */
int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las movies cargadas en el archivo binario.
 *  @param lista la lista de movies a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[]);

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




