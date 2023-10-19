section .data
    hello db 'Hello, Holberton', 0x0A, 0 ; null-terminated string with a newline

section .text
    extern printf  ; declare printf as an external function
    global _start  ; entry point for the program

_start:
    ; write the string to stdout using printf
    mov rdi, hello ; the address of the string to print
    xor rax, rax   ; make sure to clear RAX register before calling printf
    call printf    ; call printf

    ; exit the program
    mov rax, 60    ; syscall number for exit
    xor rdi, rdi   ; status 0
    syscall

