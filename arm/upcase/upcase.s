.global _start

_start:
    mov r7, #3        @ read(int fd, void *buf, size_t count)
    mov r0, #0        @ fd = stdin
    ldr r1, =char     @ buf = char
    mov r2, #1        @ count = 1
    swi 0

_uppercase:
    ldr r1, =char
    ldr r0, [r1]
    bic r0, r0, #32   @ zero out the 6th bit
    str r0, [r1]

_write:
    mov r7, #4        @ write(int fd, void *buf, size_t count)
    mov r0, #1        @ fd = stdout
    ldr r1, =char     @ buf = char
    mov r2, #1        @ count = 1
    swi 0

end:
    mov r7, #1
    swi 0

.data
char:
    .ascii " "
