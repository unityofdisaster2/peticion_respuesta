#include "Respuesta.h"
#include <string.h>
#include <stdio.h>

// dado que se debe saber los valores del origen de una conexion
// se necesario crear un paquete global que se pueda compartir 
// en la funcion getRequest y sendReply
PaqueteDatagrama bid = PaqueteDatagrama(sizeof(struct mensaje));


Respuesta::Respuesta(int pl){
    socketLocal = new SocketDatagrama(pl);
}

struct mensaje * Respuesta::getRequest(){
    // esta funcion solo se encarga de recibir 
    // el mensaje y retornarlo para ser manipulado por
    // el servidor

    socketLocal->recibe(rec);

    printf("Solicitud recibida de:\n");
    printf("direccion: %s\n",rec.obtieneDireccion());
    printf("puerto: %d\n",rec.obtienePuerto());


    return (struct mensaje*) rec.obtieneDatos();
}


void Respuesta::sendReply(char *respuesta){
    struct mensaje resultado;
    memcpy(resultado, respuesta,sizeof(respuesta));
    mensaje.operationId = 0;
    mensaje.requestId = 0;
    mensaje.messageType = 1;

    bid.inicializaDatos((char*)&mensaje);

    socketLocal->enviar(bid);

}