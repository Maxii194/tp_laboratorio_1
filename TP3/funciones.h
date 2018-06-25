#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[500];
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
 *  @param cantidad tamaño actual del array
 *  @return -
 */
void cargarPeliculas(EMovie** array,int *cantidad);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @param cantidad tamaño actual del array
 *  @param pelicula a borrar
 *  @return -
 */
void eliminarPelicula(EMovie* this[],int *cantidad,char *pelicula);


/**
 *  Muestra por pantalla todas las peliculas
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void mostrarPeliculas(EMovie* lista[],int cantidad);


/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
int generarPagina(EMovie* this[], int cantidad, int pelicula,char* path);

int movie_buscarPelicula(EMovie* this[], int cantidad, char* pelicula);
int movie_buscarIndexPelicula(EMovie* this[], int cantidad, char* pelicula);


