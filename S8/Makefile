all: exServerSocket exClientSocket sin_nombre lector escritor escritor_v2

exServerSocket: exServerSocket.c socketMng.o
	gcc -o exServerSocket exServerSocket.c socketMng.o

exClientSocket: exClientSocket.c socketMng.o
	gcc -o exClientSocket exClientSocket.c socketMng.o

socketMng.o: socketMng.c
	gcc -c socketMng.c
	
sin_nombre: sin_nombre.c
	gcc sin_nombre.c -o sin_nombre
	
lector:	lector.c
	gcc lector.c -o lector
	
escritor: escritor.c
	gcc escritor.c -o escritor

escritor_v2: escritor_v2.c
	gcc escritor_v2.c -o escritor_v2
clean: 
	rm -f exServerSocket exClientSocket socketMng.o sin_nombre lector escritor escritor_v2
