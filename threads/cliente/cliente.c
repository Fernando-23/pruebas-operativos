#include "cliente.h"

int contador_global= 0;
int quid_global = 0;
pthread_mutex_t mutex_espera;

void enviarString(char* mensajito,int socket_servidor){
	int mensajito_len = string_length(mensajito);
	
    printf("PRUEBAS - (enviarString) - Mensaje Length: %d\n",mensajito_len);
	send(socket_servidor,&mensajito_len,sizeof(int),0);
	
	printf("PRUEBAS - (enviarString) - Mensaje: %s\n",mensajito);
	send(socket_servidor,mensajito,mensajito_len,0);
}

//HAY QUE LIBERAR EN ALGUN MOMENTO ESTE MENSAJE char
Mensaje* crearMensajeRegistroQuery(char* ruta,int prioridad){
	char *mensaje = string_new();
	string_append(&mensaje,ruta);
	string_append(&mensaje," "); //divino
	string_append(&mensaje,string_itoa(prioridad));

	printf("PRUEBA - (crearMensajeRegistroQuery) - Registro concatenado: %s\n",mensaje);

	Mensaje* mensaje_registro = malloc(sizeof(Mensaje));
	mensaje_registro->mensaje = mensaje;
	mensaje_registro->size = string_length(mensaje);

	return mensaje_registro;
}

void* incrementarContador(){
	contador_global++;
	printf("PRUEBAS - (incrementarContador) - Contador en... %d\n",contador_global);
}

int gestionarOrdenMaestro(Mensaje* orden_de_mi_maestro){ //pasar logger

	char **orden_cortada = string_split(orden_de_mi_maestro->mensaje," ");
	int cod_op = atoi(orden_cortada[0]);
	switch (cod_op){
	case 0:
		char* motivo = orden_cortada[1];
		printf("###Query Finalizada - <%s>\n", motivo);
		string_array_destroy(orden_cortada);
		return 1; //terminar programa
		
		break;
	case 1:
		char* nombre_archivo = orden_cortada[1];
		char* tag = orden_cortada[2];
		char* contenido = orden_cortada[3];
		printf("### Lectura realizada: Archivo <%s:%s>, contenido: <%s>\n",nombre_archivo,tag,contenido);
		string_array_destroy(orden_cortada);
		return 0; //siga nomas
		break;
	
	default:
		printf("me llego codigo de operación erroneo: %d\n",cod_op);
		printf("desicion matar modulo\n");
		string_array_destroy(orden_cortada);
		return 1; //terminar programa
	}
}


int main(int argc,char* argv[]){

	char* ruta_arch_pseudo = argv[1];
    int prioridad = atoi(argv[2]);
	
    int fd_serv = crearConexion("127.0.0.1","9000");
	Mensaje* envio_query = crearMensajeRegistroQuery(ruta_arch_pseudo, prioridad); //handshake
    enviarMensajito(envio_query,fd_serv);
	
	// recv finalizacion -> terminas
	// recv mensaje archivo no se quje mrd -> solo logueo
	int tengo_que_seguir = 1;

	while(tengo_que_seguir){
		printf("Esperando el orden de mi maestro Master...\n");
		Mensaje* orden_de_mi_maestro = recibirMensajito(fd_serv); // aca se queda bloqueado sin espera
		tengo_que_seguir = gestionarOrdenMaestro(orden_de_mi_maestro);
		liberarMensajito(orden_de_mi_maestro);
	}

	close(fd_serv);
}