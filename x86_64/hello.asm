; hello.asm
;
; Author: Paul Riddle
; Date: Whatever

global _start

section .text:

_start:
    mov    eax, 0x4  ; use the syscall write(int fd, void *buf, size_t count)
    mov    ebx, 0x1  ; fd = stdout
    mov    ecx, message  ; buf = message
    mov    edx, message_length  ; count = message_length
    int    0x80  ; invoke the syscall

    ; successfully exit

    mov    eax, 0x1
    mov    ebx, 0
    int    0x80

section .rodata:
    message: db "Hello World!", 0xA
    message_length equ $-message
