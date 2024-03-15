%macro print 2
   mov rax,1
   mov rdi,1
   mov rsi,%1
   mov rdx,%2
   syscall
   %endmacro print



section .data
msg1 db "No in array"
len1 equ $-msg1
 
msg2 db "largest array"
len2 equ $-msg2

array db 05H,20H,0FH,0AH,07H

section .bss
count resb 1
result resb 5

section .text

global  _start
_start:
  print msg1,len1
  
  mov byte[count] ,05
  mov rsi,array
 L1:
  mov al,[rsi]
  push rsi
  call disp
  pop rsi
  inc rsi 
  dec byte[count]
  jnz L1
  
 print msg2,len2
 
 mov byte[count] ,05
 mov rsi,array
 mov al,0
 
 Repeat:
     cmp al,[rsi]
     jg Next
     mov al,[rsi] 
 Next:
     inc rsi
     dec byte [count]
     jnz Repeat
     call disp
exit:     
mov rax,60
mov rsi,0
Syscall
   
      
 disp: 
    mov bl,al
    mov rdi,result
    mov cx,02
 
    UP:
     rol bl,04
     mov al,bl
     and al,0FH
     cmp al,09
     jg ADD
     add al,30H
     jmp SKIP

   ADD:
     add al,37H

   SKIP:
    mov [rdi],al
    inc rdi
    dec cx 
   jnz UP   
   print result,05
   RET
  
  
