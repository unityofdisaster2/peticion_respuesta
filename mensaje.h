#define TAM_MAX_DATA 4000

//Definicion de identificadores para operaciones permitidas
#define suma 1

//definicion del formato de mensaje

struct mensaje{
    int messageType; //0 = Solicitud, 1 = Respuesta
    unsigned int requestId; //identificador del mensaje
    int operationId; //identificador de la operacion
    char arguments[TAM_MAX_DATA];
};
