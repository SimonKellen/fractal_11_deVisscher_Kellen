CC=gcc
AR=ar
CFLAGS=-g -Wall -W 
LDFLAGS=
SRC=buffer.c 
OBJ=$(SRC:.c=.o)
LIBFILE=libbuffer.a

all: $(SRC) $(LIBFILE)

$(LIBFILE): $(OBJ)
	$(AR) r $@ $(OBJ)

libbuffer.o: libbuffer.c libbuffer.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:libbuffer.a *.o
	rm *.o libbuffer.a
