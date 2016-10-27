# Structured makefile for camera placement
#
#

CC = gcc
LDLIBS =  -lglut -lGL -lGLU -lm
HEADERS = opengl.h structs.h globals.h constants.h prototypes.h
OBJS = init.o defineBox.o drawBox.o drawAxes.o reshape.o  

debug ?= n
ifeq ($(debug), y)
    CFLAGS += -g -DDEBUG
else
    CFLAGS += -O2 
endif


all: perspective tags 

perspective :	main.o $(OBJS) 
	$(CC) $(CFLAGS) main.o $(OBJS) -o perspective $(LDLIBS)

main.o : main.cc $(HEADERS)
	$(CC) $(CFLAGS) main.cc -c

init.o : init.cc $(HEADERS)
	$(CC) $(CFLAGS) init.cc -c

defineBox.o : defineBox.cc $(HEADERS)
	$(CC) $(CFLAGS) defineBox.cc -c

drawBox.o : drawBox.cc $(HEADERS)
	$(CC) $(CFLAGS) drawBox.cc -c

drawAxes.o : drawAxes.cc $(HEADERS)
	$(CC) $(CFLAGS) drawAxes.cc -c

reshape.o : reshape.cc $(HEADERS)
	$(CC) $(CFLAGS) reshape.cc -c

clean:
	rm *.o

pristine:
	rm *.o
	touch *

tags:
	ctags *.h *.cc
