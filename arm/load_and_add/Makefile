all: build run

build: load_and_add.o
	arm-none-eabi-ld -o load_and_add load_and_add.o

load_and_add.o: load_and_add.s
	arm-none-eabi-as -o load_and_add.o load_and_add.s

.PHONY: clean run

clean:
	rm *.o load_and_add

run:
	qemu-arm load_and_add; echo $$?
