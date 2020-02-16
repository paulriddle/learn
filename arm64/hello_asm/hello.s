        .section .rodata
mesg:   .asciz "Hello World\n"

        .text
        .global main

main:   stp x29, x30, [sp, #-16]!
        adr x0, mesg
        bl printf
        mov w0, #0
        ldp x29, x30, [sp], #16
        ret
        .size main,(. - main)
