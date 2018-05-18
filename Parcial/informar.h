
//INFORME CLIENTES

/**
 * \brief Muestra cliente con mas Avisos Activos
 * \param array de Clientes
 * \param limite de array de Clientes
 * \param array de Avisos
 * \param limite de array de Avisos
 * \return 0
 */
int informar_clienteConMasAvisosActivos(Cliente* arrayClientes, int limiteClientes,Aviso* arrayAvisos,int limiteAvisos);

/**
 * \brief Muestra cliente con mas Avisos Pausados
 * \param array de Clientes
 * \param limite de array de Clientes
 * \param array de Avisos
 * \param limite de array de Avisos
 * \return 0
 */
int informar_clienteConMasAvisosPausados(Cliente* arrayClientes, int limiteClientes,Aviso* arrayAvisos,int limiteAvisos);

/**
 * \brief Muestra cliente con mas Avisos
 * \param array de Clientes
 * \param limite de array de Clientes
 * \param array de Avisos
 * \param limite de array de Avisos
 * \return 0
 */
int informar_clienteConMasAvisos(Cliente* arrayClientes, int limiteClientes,Aviso* arrayAvisos,int limiteAvisos);


//INFORME PUBLICACIONES

/**
 * \brief Muestra cantidad de Publicaciones de rubro dado
 * \param array de Avisos
 * \param limite de array de Avisos
 * \return 0
 */
int informar_cantidadDePublicacionesXrubro(Aviso* arrayAvisos,int limiteAvisos);

/**
 * \brief Muestra rubro con mas publicaciones
 * \param array de Avisos
 * \param limite de array de Avisos
 * \return 0
 */
int informar_rubroConMasPublicaciones(Aviso* arrayAvisos,int limiteAvisos);

/**
 * \brief Muestra rubro con menos publicaciones
 * \param array de Avisos
 * \param limite de array de Avisos
 * \return 0
 */
int informar_rubroConMenosPublicaciones(Aviso* arrayAvisos,int limiteAvisos);
