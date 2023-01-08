%include "io64.inc"

section .text
global CMAIN
CMAIN:    
       
        mov rbp, rsp; for correct debugging
    
    ; 함수 (어셈블러에선 프로시저 procedure 서브루틴 subroutine이라고 한다)
    ;call PRINT_MSG
    
   
   
    PUSH 1
    PUSH 2
    call MAX
    PRINT_DEC 8, rax
    NEWLINE
    
    add rsp, 16
    
    xor rax, rax
    ret
    
MAX:
    push rbp
    mov rbp, rsp
    
    mov rax, [rbp + 16]
    mov rbx, [rbp + 24]
    cmp rax, rbx
    jg L1
    mov rax, rbx
L1:
    pop rbp
    ret
    


;초기화 된 데이터
;[변수이름] [크기] [초기값] 
;[크기] db(1)(define byte) dw(2) dd(4) dq(8)
section .data
    msg db 'Hellow World', 0x00
    a db 0x01, 0x02, 0x03, 0x04, 0x05 ; 5 * 1 = 5바이트
    b times 5 dw 1 ; 5 * 2 = 10바이트
  
    ;초기화 되지 않은 데이터
    ;[변수이름] [크기] [개수]
    ;[크기] resb(1) resw(2) resd(4) resq(8)
section .bss
    num resb 10
   