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

*.o:
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm *.o libbuffer.a
