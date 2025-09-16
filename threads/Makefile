CC = gcc
CFLAGS = -I ../utils -I ./cliente -I ./servidor
 

.PHONY = clean all

all: cliente/cliente servidor/servidor

cliente/cliente: cliente/cliente.o ../utils/utils.o
	$(CC) $(CFLAGS) -o cliente/cliente cliente/cliente.o ../utils/utils.o  -lcommons -lcrypto

servidor/servidor: servidor/servidor.o ../utils/utils.o
	$(CC) $(CFLAGS) -o servidor/servidor servidor/servidor.o ../utils/utils.o  -lcommons -lcrypto

cliente/cliente.o: cliente/cliente.c ../utils/utils.h
	$(CC) $(CFLAGS) -c cliente/cliente.c -o cliente/cliente.o

servidor/servidor.o: servidor/servidor.c ../utils/utils.h
	$(CC) $(CFLAGS) -c servidor/servidor.c -o servidor/servidor.o

../utils/utils.o: ../utils/utils.c ../utils/utils.h
	$(CC) $(CFLAGS) -c ../utils/utils.c -o ../utils/utils.o 

clean:
	rm -f  cliente/cliente.o servidor/servidor.o ../utils/utils.o
	rm -f cliente/cliente servidor/servidor


