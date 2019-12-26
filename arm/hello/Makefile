hello: hello.o
	arm-none-eabi-ld -o hello hello.o

hello.o: hello.s
	arm-none-eabi-as -o hello.o hello.s

.PHONY: clean
clean:
	rm *.o hello
