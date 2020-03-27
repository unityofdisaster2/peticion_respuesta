cliente: SocketDatagrama.o PaqueteDatagrama.o cliente.cpp
	g++ -g SocketDatagrama.o PaqueteDatagrama.o cliente.cpp -o cliente

servidor: SocketDatagrama.o PaqueteDatagrama.o servidor.cpp
	g++ -g SocketDatagrama.o PaqueteDatagrama.o servidor.cpp -o servidor


SocketDatagrama.o: SocketDatagrama.h SocketDatagrama.cpp
	g++ -g SocketDatagrama.cpp -c


PaqueteDatagrama.o: PaqueteDatagrama.h PaqueteDatagrama.cpp 
	g++ -g PaqueteDatagrama.cpp -c

