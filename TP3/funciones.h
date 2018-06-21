#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[200];
}EMovie;

#endif // FUNCIONES_H_INCLUDED
EMovie* movie_newParametros(char* titulo,char* genero,int duracion, char* descripcion, int puntaje, char* linkImagen);
EMovie* movie_new();
void movie_delete(EMovie* this);

char movie_setTitulo(EMovie* this, char* titulo);
char movie_getTitulo(EMovie* this, char* titulo);

char movie_setGenero(EMovie* this, char* genero);
char movie_getGenero(EMovie* this, char* genero);

int movie_setDuracion(EMovie* this, int duracion);
int movie_getDuracion(EMovie* this, int* duracion);

char movie_setDescripcion(EMovie* this, char* descripcion);
char movie_getDescripcion(EMovie* this, char* descripcion);

int movie_setPuntaje(EMovie* this, int puntaje);
int movie_getPuntaje(EMovie* this, int* puntaje);

char movie_setLinkImagen(EMovie* this, char* linkImagen);
char movie_getLinkImagen(EMovie* this, char* linkImagen);


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[]);


