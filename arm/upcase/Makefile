all: build run

build: upcase.o
	arm-none-eabi-ld -o upcase upcase.o

upcase.o: upcase.s
	arm-none-eabi-as -o upcase.o upcase.s

.PHONY: clean run

clean:
	rm *.o upcase

run:
	qemu-arm upcase; exit 0
