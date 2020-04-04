#include "Solicitud.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv){
	if(argc < 4){
		printf("ingresar valores en el siguiente formato:\n");
		printf("%s direccion_ip n1 n2\n",argv[0]);
		exit(0);
	}
    Solicitud sol = Solicitud();
    int argumentos[2], resultado;
    argumentos[0] = atoi(argv[2]);
    argumentos[1] = atoi(argv[3]);
    int respuesta_servidor;
	printf("se envia al servidor la operacion de suma con los valores %d %d\n",argumentos[0],argumentos[1]);
    // respuesta_servidor = sol.doOperation(argv[1],7200,1,(char*)&argumentos);
    memcpy(&respuesta_servidor, sol.doOperation(argv[1],7200,1,(char*)&argumentos), sizeof(respuesta_servidor));

    printf("si llega aqui\n");
    if(respuesta_servidor == -1){
        printf("no hay conexion con el servidor\n");
    }else{

    printf("resultado: %d + %d = %d\n",argumentos[0],argumentos[1],respuesta_servidor);

    }
    return 0;
}