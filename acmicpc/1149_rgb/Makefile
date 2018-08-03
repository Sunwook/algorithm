
.SUFFIXES: .c .o
CC = g++
LD = ld

CFLAGS  = $(INC) -g
OBJS = solve.o
SRCS = $(OBJS:.o=.c)
TARGET = $(OBJS:.o=)
	
all: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(INC) $(LDFLAGS)

dep:
	gccmakedep $(INC) $(SRCS)

clean:
	rm -rf $(OBJS)

