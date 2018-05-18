#ifndef AVISO_H_INCLUDED
#define AVISO_H_INCLUDED
typedef struct
{
    char textoAviso[64];
    int numeroRubro;
    //------------
    int estado;
    int idAviso;
    int idCliente;
}Aviso;
#endif // AVISO_H_INCLUDED


/**
 * \brief Inicializa el array de Aviso
 * \param array de Avisos
 * \param limite de array de Avisos
 * \return 0 si la entrada es correcta
 */
int aviso_init(Aviso* array,int limite);

/**
 * \brief Busca id dentro del array
 * \param array de Avisos
 * \param limite de array de Avisos
  * \param id a buscar
 * \return -1 o -2 si falla
 */
int aviso_buscarPorId(Aviso* array,int limite, int id);

/**
 * \brief Muestra todo el array de Aviso
 * \param array de Avisos
 * \param limite de array de Avisos
 * \return 0 si la entrada es correcta
 */
int aviso_mostrar(Aviso* array,int limite);

/**
 * \brief Muestra todo el array de Aviso contando los que no estan activos
 * \param array de Avisos
 * \param limite de array de Avisos
 * \return 0 si la entrada es correcta
 */
int aviso_mostrarDebug(Aviso* array,int limite);

//int aviso_modificacion(Aviso* array,int limite, int id);

/**
 * \brief Cuenta la cantidad de avisos que estan activas
 * \param array de Avisos
 * \param limite de array de Avisos
  * \param id a contar
 * \return el contador de avisos
 */
int aviso_contarxId(Aviso* array,int limite,int id);

/**
 * \brief Alta de una publicacion sin usar ciclos
 * \param array de Avisos
 * \param limite de array de Avisos
 * \param textoAviso texto del aviso
 * \param numeroRubro numero de rubro del aviso
 * \return 0 si la entrada es correcta
 */
int aviso_altaForzada(Aviso* array,int limite,char* textoAviso,int numeroRubro, int id);
