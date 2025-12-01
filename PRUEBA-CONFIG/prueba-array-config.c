#include <commons/log.h>
#include <commons/string.h>
#include <commons/config.h>
#include <commons/collections/list.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>



void agregarBlockAMetadata(char** array_a_agregar){

    //log_debug()
}

int main(){
    t_config* config = config_create("prueba.config");
    
    char** array = config_get_array_value(config,"BLOCKS");
    

    string_array_push(&array,string_duplicate("0"));//{2,10,0}
    string_array_push(&array,string_duplicate("0"));//{2,10,0,0}
    string_array_push(&array,string_duplicate("0"));//{2,10.0,0,0}
    printf("bloques del array despues de pushear nuevos bloques:\n");
    printf("%d\n",string_array_size(array));
    
    char* string_blocks_a_reemplazar = string_new();
    string_append(&string_blocks_a_reemplazar,"[");

    for (int i = 0; i < string_array_size(array); i++){
        
        string_append(&string_blocks_a_reemplazar,array[i]);

        if (i != string_array_size(array)-1){
            string_append(&string_blocks_a_reemplazar,",");
        }
    }
    //string_append(&string_blocks_a_reemplazar,array[(string_array_size(array)-1)]);
    string_append(&string_blocks_a_reemplazar,"]");
    printf("%s\n",string_blocks_a_reemplazar);

    config_set_value(config,"BLOCKS",string_blocks_a_reemplazar);
    config_save(config);

    sleep(3);

    free(string_blocks_a_reemplazar);
    string_array_destroy(array);
    config_destroy(config);
}
