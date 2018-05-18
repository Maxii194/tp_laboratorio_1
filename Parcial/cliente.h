#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    char cuit[20];
    //------------
    int idCliente;
    int isEmpty;
}Cliente;
#endif // CLIENTE_H_INCLUDED

/**
 * \brief Inicializa el array de Cliente
 * \param array de Cliente
 * \param limite de array de Cliente
 * \return 0 si la entrada es correcta
 */
int cliente_init(Cliente* array,int limite);

/**
 * \brief Busca id dentro del array
 * \param array de Cliente
 * \param limite de array de Cliente
  * \param id a buscar
 * \return -1 o -2 si falla
 */
int cliente_buscarPorId(Cliente* array,int limite, int id);

/**
 * \brief Baja de un cliente
 * \param array de Cliente
 * \param limite de array de Cliente
  * \param id a buscar
 * \return -1 o -2 si falla
 */
int cliente_baja(Cliente* array,int limite, int id);

/**
 * \brief Muestra el array de cliente
 * \param array de Cliente
 * \param limite de array de Cliente
 * \return 0 si la entrada es correcta
 */
int cliente_mostrar(Cliente* array,int limite);

/**
 * \brief Muestra el array de cliente sin filtrar los no activos
 * \param array de Cliente
 * \param limite de array de Cliente
 * \return 0 si la entrada es correcta
 */
int cliente_mostrarDebug(Cliente* array,int limite);

/**
 * \brief Carga el array de cliente
 * \param array de Cliente
 * \param limite de array de Cliente
 * \return 0 si la entrada es correcta
 */
int cliente_alta(Cliente* array,int limite);

/**
 * \brief Modifica el array de un cliente
 * \param array de Cliente
 * \param limite de array de Cliente
  * \param id Cliente a buscar
 * \return 0 si la entrada es correcta
 */
int cliente_modificacion(Cliente* array,int limite, int id);

/**
 * \brief Ordena el array de clientes
 * \param array de Cliente
 * \param limite de array de Cliente
  * \param orden a ordenar
 * \return 0 si la entrada es correcta
 */
int cliente_ordenar(Cliente* array,int limite, int orden);

/**
 * \brief Alta de una cliente sin usar ciclos
 * \param array de Clientes
 * \param limite de array de Clientes
 * \param nombre del cliente
  * \param apellido del cliente
 * \param cuit numero del cliente
 * \return 0 si la entrada es correcta
 */
int cliente_altaForzada(Cliente* array,int limite,char* nombre,char* apellido, char* cuit);

