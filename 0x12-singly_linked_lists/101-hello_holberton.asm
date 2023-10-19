section .data
    hello db 'Hello, Holberton',0

section .text
    extern  printf
    global _start

_start:
    ; prepare arguments for printf
    mov rdi, hello    ; pointer to format string
    xor rax, rax      ; no floating point arguments
    call printf

    ; exit syscall
    mov rax, 60       ; syscall number for exit
    xor rdi, rdi      ; status 0
    syscall

