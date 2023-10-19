section .data
    hello db 'Hello, Holberton',0x0A  ; Null-terminated string to print
    hello_len equ $ - hello           ; Calculate the length of the string

section .text
    global _start                     ; Entry point for the program

_start:
    ; sys_write (ssize_t write(int fd, const void *buf, size_t count))
    mov rax, 1                        ; syscall number for sys_write
    mov rdi, 1                        ; file descriptor stdout
    mov rsi, hello                    ; pointer to the string to print
    mov rdx, hello_len                ; length of the string to print
    syscall                           ; invoke syscall

    ; sys_exit (void _exit(int status))
    mov rax, 60                       ; syscall number for sys_exit
    xor rdi, rdi                      ; status 0
    syscall                           ; invoke syscall

