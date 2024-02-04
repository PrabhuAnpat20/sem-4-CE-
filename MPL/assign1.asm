section .data
  msg1 db "enter string",10,13
  len1 equ $-msg1
  msg2 db "length of string",10,13
  len2 equ $-msg2
section .bss
  str resb 100
  res resb 16
section .text
  global _start
  _start:
  mov rax,1
  mov rdi,1
  mov rsi,msg1
  mov rdx,len1
  syscall  
   mov rax,0
   mov rdi,0
   mov rbx,str
   mov rdx,100
   
   mov rbx,rax
   mov rdi,res
   mov cx,16
   
   L1:rol rbx,04
      mov al,bl
      and al,0fh
      cmp al,09
      jg L2
      
      add al,30h
      jmp L3
      
  L2: add al,37h
  
  L3:mov rdi,al
     inc rdi
     dec cx
     jnz L1
    
  mov rax,1
  mov rdi,1
  mov rsi,msg2
  mov rdx,len2
  
  mov rax,1
  mov rdi,1
  mov rsi,res
  mov rdx,16
   
   
          
  mov rax,60
  mov rdi,0
  syscall  
