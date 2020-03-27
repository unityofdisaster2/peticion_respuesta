#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <stdio.h>

int main(){
    SocketDatagrama cliente =  SocketDatagrama(0);
    char * mensaje = {"hola"};
    PaqueteDatagrama envia_p = PaqueteDatagrama(mensaje,sizeof(mensaje),(char*)"127.0.0.1",7200);
    cliente.envia(envia_p);

}