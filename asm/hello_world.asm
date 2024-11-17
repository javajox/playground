section .data
   msg db 'Hello, World!', 0xa  ; Message with newline
   len equ $ - msg              ; Length of message

section .text
   global _start

_start:
   mov rax, 1      ; syscall: write      
   mov rdi, 1      ; file descriptor: stdout
   mov rsi, msg    ; message to write
   mov rdx, len    ; message length
   syscall         ; call kernel

   mov rax, 60     ; syscall: exit
   mov rdi, 0      ; exit code 0
   syscall

;; How to compile, link and run
;; # Compile
;; yasm -f elf64 -g dwarf2 program.asm
;; ld -o program program.o

;; Debug with GDB
;; gdb ./program
;; (gdb) layout asm    # View assembly
;; (gdb) break _start  # Set breakpoint
;; (gdb) run          # Run program
;; (gdb) si           # Step instruction
;; (gdb) info registers # View registers