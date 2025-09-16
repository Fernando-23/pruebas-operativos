#include "utils.h"


int crearConexion(char *ip, char* puerto)
{
    struct addrinfo hints;
    struct addrinfo *server_info;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo(ip, puerto, &hints, &server_info);

    int socket_cliente = socket(server_info->ai_family,
                            	server_info->ai_socktype,
                            	server_info->ai_protocol);

    if(connect(socket_cliente, server_info->ai_addr, server_info->ai_addrlen) == -1){
        perror("No se pudo conectar");
        return -1;
    }

    freeaddrinfo(server_info);
    return socket_cliente;
}


int iniciarServidor(char *puerto){
	int socket_servidor;

	struct addrinfo hints;
	struct addrinfo *servinfo;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(NULL, puerto, &hints, &servinfo);

	// Creo el socket de escucha del servidor
	socket_servidor = socket(servinfo->ai_family,
							 servinfo->ai_socktype,
							 servinfo->ai_protocol);

	// Asociamos el socket a un puerto
	bind(socket_servidor, servinfo->ai_addr, servinfo->ai_addrlen);

	// Escuchamos las conexiones entrantes
	listen(socket_servidor, SOMAXCONN);

	freeaddrinfo(servinfo);
	printf("Listo para escuchar a mi cliente \n");
	printf( "Servidor listo para recibir clientes...\n");

	return socket_servidor;
}

int esperarCliente(int socket_servidor){ //santi, no se entendio

    // Aceptamos un nuevo cliente
    int socket_cliente = accept(socket_servidor,NULL,NULL);
    printf("Se conecto un cliente!\n");

    return socket_cliente;
}
