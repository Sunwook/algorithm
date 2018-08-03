
.SUFFIXES: .c .o
CC = gcc
LD = ld

CFLAGS  = $(INC)
#LDFLAGS = -lglib-2.0
#INC = -I/usr/include/glib-2.0 -I/usr/lib/i386-linux-gnu/glib-2.0/include
OBJS = asymtiling.o
SRCS = $(OBJS:.o=.c)
TARGET = $(OBJS:.o=)
	
all: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(INC) $(LDFLAGS)

dep:
	gccmakedep $(INC) $(SRCS)

clean:
	rm -rf $(OBJS)

