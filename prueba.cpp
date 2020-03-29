#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
struct mensaje{
    int messageType; //0 = Solicitud, 1 = Respuesta
    unsigned int requestId; //identificador del mensaje
    int operationId; //identificador de la operacion
    char arguments[4000];
};



int main (void){
    struct mensaje msj;
    struct mensaje *msjMem;
    char * datos;
    char argumentos[2];
    argumentos[0] = '2';
    argumentos[1] = '7';
    msj.messageType = 0;
    msj.requestId = 1;
    msj.operationId = 1;
    memcpy(msj.arguments,argumentos,sizeof(argumentos));

    datos = new char[sizeof(msj)];
    memcpy(datos,(char*)&msj,sizeof(msj));

    msjMem = (struct mensaje *)datos;

    printf("%s\n",msjMem->arguments);
}
