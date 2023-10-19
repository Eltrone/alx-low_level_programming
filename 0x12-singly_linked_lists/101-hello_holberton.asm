section .data
    hello db 'Hello, Holberton', 0x0A, 0 ; null-terminated string with a newline

section .text
    extern printf  ; declare printf as an external function
    extern exit    ; declare exit as an external function
    global main    ; entry point for the program should now be main instead of _start

main:
    ; write the string to stdout using printf
    mov rdi, hello ; the address of the string to print
    xor rax, rax   ; make sure to clear RAX register before calling printf
    call printf    ; call printf

    ; exit the program using exit function
    xor rdi, rdi   ; status 0
    call exit      ; call exit

