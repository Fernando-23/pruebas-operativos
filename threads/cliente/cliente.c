#include "cliente.h"

int contador_global= 0;

void EnviarString(char* mensajito,int socket_servidor){
	int mensajito_len = string_length(mensajito);
	
    printf("PRUEBAS - (enviarString) - Mensaje Length: %d\n",mensajito_len);
	send(socket_servidor,&mensajito_len,sizeof(int),0);
	
	printf("PRUEBAS - (enviarString) - Mensaje: %s\n",mensajito);
	send(socket_servidor,mensajito,mensajito_len,0);
}

void* incrementarContador(){
	contador_global++;
	printf("PRUEBAS - (incrementarContador) - Contador en... %d\n",contador_global);
}

int main(){

	// pthread_t thread_contador;

	// pthread_create(&thread_contador,NULL,incrementarContador,NULL); 

	// pthread_join(thread_contador,NULL);
	

    int fd_algo = crearConexion("127.0.0.1","9000");
    EnviarString("Mensajito de prueba",fd_algo);
	
	while(1){
		
	}
}