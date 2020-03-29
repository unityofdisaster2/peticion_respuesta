#include "Solicitud.h"
#include <stdio.h>

int main(){
    Solicitud sol = Solicitud();
    char argumentos[2];
    argumentos[0] = 5;
    argumentos[1] = 2;
    char * respuesta_servidor;
    respuesta_servidor = sol.doOperation((char*)"127.0.0.1",7200,1,argumentos);
    printf("5 + 2 = %d\n",respuesta_servidor[0]);
    return 0;
}