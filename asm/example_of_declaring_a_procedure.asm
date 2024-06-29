section .data
   msg db 'Hello, World!', 0xA   ; The message to be printed follwed by a new line character
   len equ $ - msg
   
section .text
   global _start
   ;extern write_message
   
_start:
   call write_message        ; Call the function to write the message
   
   ; Prepare for the exit system call
   mov eax, 60		     ; System call number for sys_exit
   xor edi, edi              ; Exit code 0
   syscall
   
write_message:
   ; Prepare for the write system call
   mov eax, 1                ; System call number for sys_write
   mov edi, 1                ; File descriptor 1 (stdout)
   mov rsi, msg              ; Pointer to the message to write
   mov edx, len              ; Length of the message
   syscall
   
   ret                       ; Return from the function   
