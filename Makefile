CC=gcc
CFLAGS=-g
TARGET=add-nbo

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
	rm -f *.o
