.PHONY: run clean

##var
LISTAS=listas
CFLAGS=-lcommons -lcrypto

run: $(LISTAS)
	./$(LISTAS)

clean:
	rm $(LISTAS) $(LISTAS).o

$(LISTAS): $(LISTAS).o
	gcc $(LISTAS).o -o $(LISTAS) $(CFLAGS)

$(LISTAS).o: $(LISTAS)-pruebas.c
	gcc -c $(LISTAS)-pruebas.c -o $(LISTAS).o

