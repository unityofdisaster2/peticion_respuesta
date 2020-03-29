#include "Respuesta.h"
#include <stdio.h>
#include <stdlib.h>
// Operacion 1
char operacion1(char a, char b){
    return a + b;
}


int main(){
    Respuesta res = Respuesta(7200);
    while(1){
        struct mensaje* msj = res.getRequest();
        printf("%d\n",msj->operationId);
        //printf("llega en el main %d\n",msjEntrada->operationId);
        // if (msjEntrada.operationId == 1){
        //     printf("llega en el main2\n");
        //     printf("suma %d\n",resultado);
        // }
        //res.sendReply((char *)&resultado); 
    }

}