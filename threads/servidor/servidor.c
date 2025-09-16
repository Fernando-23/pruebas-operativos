#include "servidor.h"

//tambien printea
void RecibirString(Mensaje* mensajito_a_recibir,int socket_cliente){


    recv(socket_cliente, &(mensajito_a_recibir->size), sizeof(int), MSG_WAITALL);
    printf("PRUEBAS - (RecibirString) - Recibi el tamanio: %d\n",mensajito_a_recibir->size);
   
    mensajito_a_recibir->mensaje = malloc(mensajito_a_recibir->size);
    
    recv(socket_cliente, mensajito_a_recibir->mensaje, mensajito_a_recibir->size, MSG_WAITALL);
    printf("PRUEBAS - (RecibirString) - Recibi el mensaje: %s\n",mensajito_a_recibir->mensaje);
}

void* esperarClienteVoid(void* args){
    int socket = *(int*)args; //clarisimo mi rey
    
    int fd_cliente = esperarCliente(socket);
    Mensaje* mensaje_a_recibir = malloc(sizeof(Mensaje));
    RecibirString(mensaje_a_recibir,fd_cliente);

    free(mensaje_a_recibir);
    while(1){
        
    }
}


int main(){
    int socket = iniciarServidor("9000");

    pthread_t thread_multihilo[4]; //que fumada

    /* Esta cosa deberia hacerse solamente si pasas + de 1 parametro a la func del hilo
    ArgsEsperarCliente* args_multihilo;
    args_multihilo.socket=socket;
    pthread_create(&thread_multihilo,NULL,esperarClienteVoid,(void *)args_multihilo);
    */
    for (size_t i = 0; i < 4; i++)
    {
        pthread_create(&thread_multihilo[i],NULL,esperarClienteVoid,(void *)&socket);
    }
    
    for (size_t i = 0; i < 4; i++)
    {
        pthread_join(thread_multihilo[i],NULL);
    }


}