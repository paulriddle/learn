all: build run

build: bic.o
	arm-none-eabi-ld -o bic bic.o

bic.o: bic.s
	arm-none-eabi-as -o bic.o bic.s

.PHONY: clean run

clean:
	rm *.o bic

run:
	qemu-arm bic; echo $$?
