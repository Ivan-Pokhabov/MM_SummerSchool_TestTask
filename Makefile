.PHONY: all clean

TARGET = bmp

all : $(TARGET)

clean:
	rm -f src/*.o $(TARGET) $(TARGET)

$(TARGET).o:
	gcc -c src/$(TARGET).c -o src/$(TARGET).o

$(TARGET): bmp.o
	gcc src/$(TARGET).o -o $(TARGET)

build:
	arm-linux-gnueabi-gcc -static src/$(TARGET).c -o $(TARGET)