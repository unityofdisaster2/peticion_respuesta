#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <stdio.h>

int main(){
    SocketDatagrama servidor =  SocketDatagrama(7200);
    PaqueteDatagrama recibido = PaqueteDatagrama(5);

    servidor.recibe(recibido);

    printf("%s\n",recibido.obtieneDatos());


}