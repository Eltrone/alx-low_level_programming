section .data
    hello_message db 'Hello, Holberton', 10, 0 ; 10 is the ASCII code for newline

section .text
    extern printf  ; Declare printf as an external function

    global _start ; Entry point for the program

_start:
    ; Prepare arguments for printf
    mov rdi, hello_message ; First argument: format string
    xor rax, rax ; Clear rax to initialize varargs count to zero

    ; Call printf
    call printf

    ; Exit the program
    mov rdi, 0  ; return code
    mov rax, 60 ; syscall number for exit
    syscall

