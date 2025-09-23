#include "servidor-desalojo.h"

int quid_global = 0;
t_list* lista_ready;

void* gestionarQueryIndividual(void* args){
    int fd_cliente = *(int*)args; //clarisimo mi rey
    Mensaje* mensaje_a_recibir = recibirMensajito(fd_cliente);
    printf("Voy a hacer el biribara \n");
    char** mensajito_cortado = string_split(mensaje_a_recibir->mensaje," ");
    char* path_query = mensajito_cortado[0];
    int prioridad = atoi(mensajito_cortado[1]);
    
    printf("Despues de todo el biribara, path query:%s prioridad:%d\n",path_query,prioridad);
    string_array_destroy(mensajito_cortado);

    liberarMensajito(mensaje_a_recibir);
}


void* atenderQuerys(void *args){
    int socket = *(int*)args;
    
    while(1){
        int fd_cliente = esperarCliente(socket);

        pthread_t thread_query;
        pthread_create(&thread_query,NULL,gestionarQueryIndividual,(void *)&fd_cliente);
        pthread_detach(thread_query); //creo que no hace falta, pero pensar a futuro
        
    }
    
}

void CrearQCB(char* query, int prioridad,int fd){
    //LIBERAR MEMORIA DE QCB
    QCB* qcb = malloc(sizeof(QCB));
    qcb->query = query;
    qcb->prioridad = prioridad;
    qcb->quid = quid_global;
    qcb->fd = fd;

    //wait
    quid_global++;
    //signal

    list_add(lista_ready, qcb);
    //log_debug(logger_master, "Debug - (CrearQCB) - Se creo el QCB con Quid: %d, Prioridad: %d y Query: %s", qcb->quid, qcb->prioridad, qcb->query);

}

/*
void *gestionarWorkerIndividual(void *args){
    int fd_cliente = *(int*)args; //clarisimo mi rey
    Mensaje* mensaje_a_recibir = recibirMensajito(fd_cliente);
    char** mensajito_cortado = string_split(mensaje_a_recibir->mensaje," ");
    char* path_query = mensajito_cortado[0];
    int prioridad = atoi(mensajito_cortado[1]);
    
    printf("Despues de todo el biribara, path query:%s prioridad:%d",path_query,prioridad);
    string_array_destroy(mensajito_cortado);

    liberarMensajito(mensaje_a_recibir);
}

void* atenderWorker(void *args){
    int socket = *(int*)args;
    
    while(1){
        int fd_cliente = esperarCliente(socket);
        pthread_t thread_worker;
        pthread_create(&thread_worker,NULL,gestionarWorkerIndividual,(void *)&fd_cliente);
        pthread_detach(thread_worker);
    }
}
*/
int main(int argc,char* argv[]){

    //char *path_config = argv[1];
    //t_config* config_servidor = config_create(path_config);

    int socket_query = iniciarServidor("9000");
    //int socket_worker = iniciarServidor("9001");

    pthread_t thread_adm_query; //que fumada. edit 16/9 no era tan fumada
    //pthread_t thread_worker;
    lista_ready = list_create();

    //thread que crean threads
    pthread_create(&thread_adm_query,NULL,atenderQuerys,(void *)&socket_query); // while condicion de corte phread on demand
    //pthread_create(&thread_worker,NULL,atenderWorker,(void *)&socket_worker); // idem 

    pthread_join(thread_adm_query,NULL);
    //pthread_join(thread_worker,NULL);


}




/* Esta cosa deberia hacerse solamente si pasas + de 1 parametro a la func del hilo
    ArgsEsperarCliente* args_multihilo;
    args_multihilo.socket=socket;
    pthread_create(&thread_multihilo,NULL,esperarClienteVoid,(void *)args_multihilo);
*/