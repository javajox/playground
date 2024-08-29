section .text
global _start

_start:
    mov rax, 60       ; syscall number for sys_exit in 64-bit Linux
    xor edi, edi      ; Exit status 0
    syscall           ; Make the system call

