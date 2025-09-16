#include "listas-pruebas.h"


int quid_global = 0;
t_list* lista_ready; 

void crearQCBMock(Qcb* qcb,char* query){
    qcb->query = query;
    qcb->quid = quid_global;

    //wait
    quid_global++;
    //signal
    list_add(lista_ready, qcb);
    //printf("Debug - (CrearQCB) - Se creo el QCB con Quid: %d y Query: %s", qcb->quid, qcb->query);

} 

void mostrarLista(void* qcb_void){
    Qcb* qcb_a_mostrar = (Qcb *)qcb_void;
    printf("QCB - id:%d, query:%s \n",qcb_a_mostrar->quid,qcb_a_mostrar->query);
}

void detonarQcb(void* qcb){
    Qcb *qcb_a_detonar = (Qcb *)qcb;
    free(qcb_a_detonar);
}



int main (){

    lista_ready = list_create();
    Qcb* qcb_1 = malloc(sizeof(Qcb));
    Qcb* qcb_2 = malloc(sizeof(Qcb));
    Qcb* qcb_3 = malloc(sizeof(Qcb));
    Qcb* qcb_4 = malloc(sizeof(Qcb));
    Qcb* qcb_5 = malloc(sizeof(Qcb));

    crearQCBMock(qcb_1,"santi");
    crearQCBMock(qcb_2,"liam");
    crearQCBMock(qcb_3,"fer");
    crearQCBMock(qcb_4,"agus");
    crearQCBMock(qcb_5,"abi");
    

    list_iterate(lista_ready, mostrarLista);
  
    list_destroy_and_destroy_elements(lista_ready,detonarQcb);
    // list_destroy_and_destroy_elements(lista_ready,detonarQcb); //variante, hace lo mismo
    //list_iterate(lista_ready, mostrarLista); //aca deberia romper, no existe nada

    printf("qcb_1 id: %d \n",qcb_1->quid);
    
}
