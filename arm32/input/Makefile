input: input.o
	arm-none-eabi-ld -o input input.o

input.o: input.s
	arm-none-eabi-as -o input.o input.s

.PHONY: clean
clean:
	rm *.o input
