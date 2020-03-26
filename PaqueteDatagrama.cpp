#include "PaqueteDatagrama.h"
#include <string.h>
PaqueteDatagrama::PaqueteDatagrama(char * cadena, unsigned int longit, char *dir, int pt){
    longitud = longit;
    datos = new char[longitud];

    memcpy(ip,dir,sizeof(ip));
    puerto = pt;
    memcpy(datos,cadena,longitud);
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int longit){
    datos = new char[longitud];
    longitud = longit;
}

PaqueteDatagrama::~PaqueteDatagrama(){
    delete [] datos;
    delete [] ip;
    longitud = 0;
    puerto = 0;
}

char * PaqueteDatagrama::obtieneDatos(){
    return datos;
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
    return longitud;
}

int PaqueteDatagrama::obtienePuerto(){
    return puerto;
}

char *PaqueteDatagrama::obtieneDireccion(){
    return ip;
}


void PaqueteDatagrama::inicializaPuerto(int pp){
    puerto = pp;
}

void PaqueteDatagrama::inicializaDatos(char * dd){
    memcpy(datos,dd,longitud);
}

void PaqueteDatagrama::inicializaIp(char * dir){
    memcpy(ip,dir,sizeof(ip));
}