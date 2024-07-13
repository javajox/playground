section .data
   num1 db 5		; First number
   num2 db 10		; Second number
   msg_equal db 'Numbers are equal', 0
   msg_less db 'num1 is less than num2', 0
   msg_greater db 'num1 is greater than num2', 0
   
;section .bss
;   len equ $-msg_equal
   
section .text
   global _start
   
_start:
   ; Load the values into registers
   mov al, [num1]
   mov bl, [num2]
   
   ; Compare the values
   cmp al, bl
   je equal
   jl less
   jg greater
   
equal:
   ; Print "Numbers are equal"
   mov edx, 18
   mov ecx, msg_equal
   jmp print
   
less:
   ; Print "num1 is less than num2"
   mov edx, 22
   mov ecx, msg_less
   jmp print
   
greater:
   ; Print "num1 is greater than num2"
   mov edx, 24
   mov ecx, msg_greater
   
print:
   ; Print the message
   mov ebx, 1     ; File descriptor (stdout)
   mov eax, 4     ; System call number (sys_write)
   int 0x80       ; Kernel call
   
   ; Exit the program
   mov eax, 1     ; System call number (sys_exit)
   xor ebx, ebx   ; Exit code 0
   int 0x80       ; Kernel call                
