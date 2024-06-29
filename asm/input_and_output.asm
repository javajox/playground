section .bss
buffer resb 128		; Reserve 128 bytes for user input

section .text
global _start


_start:

   ; Read input
   mov eax, 0		; sys_read
   mov edi, 0		; stdion
   mov rsi, buffer	; buffer to store input
   mov edx, 128		; max bytes to read
   syscall
   
   ; Write output
   mov eax, 1		; sys_write
   mov edi, 1		; stdout
   mov rsi, buffer	; buffer to write
   mov edx, 128		; max bytes to write
   syscall
   
   ; Exit
   mov eax, 60		; sys_exit
   xor edi, edi		; exit code 0
   syscall
