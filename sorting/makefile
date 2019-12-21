CC = gcc
CFLAGS = -g -Wall
SRCS = $(wildcard *.c)
TARGET = $(SRCS:%.c=%)

all : $(TARGET)

$(TARGET) : $(SRCS)
	$(CC) $(CFLAGS) -o $@ $<

.PHONY : clean
clean : 
	rm $(TARGET)