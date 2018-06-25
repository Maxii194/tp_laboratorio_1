#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"
#define qtyMaximaArrayPeliculas 5



int main()
{
    int opcion;
    char peliculaEliminar[50];
    char peliculaGenerar[50];
    int aux;

    EMovie* pArrayPeliculas[5];
    int qtyActualArrayPeliculas = 0;

    pArrayPeliculas[qtyActualArrayPeliculas] = movie_newParametros("Inception","Ciencia Ficcion",120,"Inception is a movie starring Leonardo DiCaprio, Joseph Gordon-Levitt, and Ellen Page. A thief, who steals corporate secrets through the use of dream-sharing technology, is given the inverse task of planting an idea into the mind of a CEO.",100,"https://m.media-amazon.com/images/M/MV5BMjAxMzY3NjcxNF5BMl5BanBnXkFtZTcwNTI5OTM0Mw@@._V1_UX182_CR0,0,182,268_AL_.jpg");
    qtyActualArrayPeliculas++;
    /*pArrayPeliculas[qtyActualArrayPeliculas] = movie_newParametros("Banieros","Comedia",3," 404 ",10," 404 ");
    qtyActualArrayPeliculas++;*/
    pArrayPeliculas[qtyActualArrayPeliculas] = movie_newParametros("Titanic","Drama",200,"Titanic, American romantic adventure film, released in 1997, that centres on the sinking of the RMS Titanic. The film proved immensely popular, holding the all-time box-office gross record for more than a decade after its release.",100,"https://static.rogerebert.com/uploads/movie/movie_poster/titanic-1997/large_s2Z25JcBWS9tKAysSKuWyon5lwP.jpg");
    qtyActualArrayPeliculas++;
    /*pArrayPeliculas[qtyActualArrayPeliculas] = movie_newParametros("Taken","Accion",3," 404 ",10," 404 ");
    qtyActualArrayPeliculas++;*/





    do
    {
        getValidInt("\n\n1.Agregar Pelicula\n2.Borrar Pelicula\n3.Generar Pelicula\n4.Salir\n","\nNo Valida",&opcion,1,4,1);
        switch(opcion)
        {
            case 1:
                cargarPeliculas(pArrayPeliculas,&qtyActualArrayPeliculas);
                break;
            case 2:
                if(getValidAlfaNumerico("Titulo: ","Error\n","Overflow", peliculaEliminar,50,2)==0 && movie_buscarPelicula(pArrayPeliculas,qtyActualArrayPeliculas,peliculaEliminar)==0){

                    eliminarPelicula(pArrayPeliculas,&qtyActualArrayPeliculas,peliculaEliminar);
                    qtyActualArrayPeliculas--;
                    printf("Pelicula Eliminada\n");
                }
                else{
                   printf("Pelicula no Encontrada\n");
                }
                break;
            case 3:
                if(getValidAlfaNumerico("Titulo: ","Error\n","Overflow", peliculaGenerar,50,2)==0 && movie_buscarPelicula(pArrayPeliculas,qtyActualArrayPeliculas,peliculaGenerar)==0){

                    aux = movie_buscarIndexPelicula(pArrayPeliculas,qtyActualArrayPeliculas,peliculaGenerar);
                    strcat(peliculaGenerar,".html");
                    generarPagina(pArrayPeliculas,qtyActualArrayPeliculas,aux,peliculaGenerar);
                    printf("Archivo html generado\n");
                     system("PAUSE");
                }
                else{
                   printf("Pelicula no Encontrada\n");

                }
                break;
        }
    }while(opcion!=4);

    //mostrarPeliculas(pArrayPeliculas,qtyActualArrayPeliculas);
    return 0;
}

