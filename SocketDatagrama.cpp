#include "SocketDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <stdio.h>
#include <strings.h>
#include <arpa/inet.h>

SocketDatagrama::SocketDatagrama(int pto){
    s = socket(AF_INET, SOCK_DGRAM,0);
    bzero((char*)&direccionLocal,sizeof(direccionLocal));
    bzero((char*)&direccionForanea,sizeof(direccionForanea));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(pto);
    bind(s,(struct sockaddr *)&direccionLocal,sizeof(direccionLocal));
}

SocketDatagrama::~SocketDatagrama(){

}

int SocketDatagrama::envia(PaqueteDatagrama &p){
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    direccionForanea.sin_port = htons(p.obtienePuerto());
    printf("si llega aqui\n");
    sendto(s, (char *)p.obtieneDatos(),sizeof(p.obtieneDatos()),0,(sockaddr *)&direccionForanea,sizeof(direccionForanea));
    return 0;
}

int SocketDatagrama::recibe(PaqueteDatagrama &p){
    socklen_t clilen = sizeof(direccionForanea);
    recvfrom(s,(char *)p.obtieneDatos(),sizeof(p.obtieneDatos()),0,(struct sockaddr *)&direccionForanea,&clilen);
    return 0;
}