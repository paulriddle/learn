all: build run

build: max.o
	arm-none-eabi-ld -o max max.o

max.o: max.s
	arm-none-eabi-as -o max.o max.s

.PHONY: clean run

clean:
	rm *.o max

run:
	qemu-arm max; echo $$?
