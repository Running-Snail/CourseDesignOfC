#makefile for science  simulation platform

CC = gcc
CFLAGS = -w
GTK = $(shell pkg-config --cflags --libs gtk+-3.0)
INCLUDE_DIR = -I./
LIB_DIR = -L/usr/local/lib
LIBS = -lm
CS = $(shell find ./ -regex "^.*\.c")
OBJS = $(patsubst %.cpp,%.o,$(CS))

all: go

go: $(OBJS)
	$(CC) $(OBJS) $(GTK) $(LIB_DIR) $(LIBS) -o $@ 

%.o : %.c
	$(CC) $^ $(INCLUDE_DIR) $(GTK) $(LIB_DIR) $(LIBS) -c -o $@

clean:
	rm -rf *.o go
