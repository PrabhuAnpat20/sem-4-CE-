section .data
msg1 db "Enter the string"
len1 equ $-msg1

msg2 db " Display the string"
len2 equ $-msg2

section .bss
string resb 100
res resb 16

section .text

global  _start
_start:
mov rax,1    ;DISPLAY THE STRING
mov rdi,1
mov rsi,msg1
mov rdx,len1
Syscall

;READ THE STRING
mov rax,0
mov rdi,0
mov rsi,string
mov rdx,100
Syscall
mov rbx,rax
mov rdi,res
mov cx,16

L1:
rol rbx,04
mov al,bl
and al,0FH
cmp al,09
jg L2
add al,30H
jmp L3

L2:
add al,37H

L3:
mov [rdi],al
inc rdi
dec cx 
jnz L1

mov rax,1    
mov rdi,1
mov rsi,msg2
mov rdx,len2
Syscall

mov rax,1    
mov rdi,1
mov rsi,res
mov rdx,16
Syscall


mov rax,60
mov rsi,0
Syscall


