all: exec

exec: main.c lib
	gcc -o main main.c libfractal/libfractal.a libbuffer/libbuffer.a -lpthread -lSDL
	
lib:
	cd libfractal && $(MAKE) clean && $(MAKE)
	cd libbuffer && $(MAKE) clean && $(MAKE)

clean:
	rm main
	cd libfractal && $(MAKE) clean
	cd libbuffer && $(MAKE) clean
