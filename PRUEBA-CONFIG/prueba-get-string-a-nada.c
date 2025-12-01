#include <commons/log.h>
#include <commons/string.h>
#include <commons/config.h>
#include <commons/crypto.h>
#include <commons/collections/list.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


int main(){
    t_config* config = config_create("prueba.config");
    char* prueba = crypto_md5("hola",4); 
    //printf("%s\n",prueba);
    config_set_value(config,prueba,"prueba");
    //config_save(config);
    //free(prueba);
    
    printf("pausita para breakpoint, valor %s\n",config_get_string_value(config,"4d186321c1a7f0f354b297e8914ab240"));

    config_destroy(config);
    //esto_deberia_ser_null = NULL;
    //config_destroy(config);
}
