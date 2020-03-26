#ifndef RESPUESTA_H_
#define RESPUESTA_H_


class Respuesta{
    public:
        Respuesta(int pl);
        struct mensaje *getRequest(void);
        void sendReply(char *Respuesta);
    private:
        SocketDatagrama *socketLocal;
};

#endif