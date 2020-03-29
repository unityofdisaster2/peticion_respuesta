#include "Respuesta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Operacion 1
char operacion1(char a, char b){
    return a + b;
}


int main(){
    Respuesta res = Respuesta(7200);
    while(1){
        struct mensaje* msj = res.getRequest();
        if(msj->operationId == 1){
            int argumentos[2],resultado;
            printf("\nejecutando operacion de suma...\n");
            memcpy(argumentos,msj->arguments, sizeof(msj->arguments));
            resultado = operacion1(argumentos[0],argumentos[1]);
            printf("\nresultado de la operacion %d\n",resultado);
            printf("enviando respuesta a cliente...\n");
            res.sendReply((char *)&resultado);
        }
    }

}