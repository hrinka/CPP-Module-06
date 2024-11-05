CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = convert

all: $(TARGET)

$(TARGET): main.o Serializer.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o Serializer.o

main.o: main.cpp Serializer.hpp Data.hpp
	$(CC) $(CFLAGS) -c main.cpp

Serializer.o: Serializer.cpp Serializer.hpp Data.hpp
	$(CC) $(CFLAGS) -c Serializer.cpp

clean:
	rm -f *.o $(TARGET)

re: clean all
