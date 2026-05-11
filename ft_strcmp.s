global ft_strcmp

section .text

ft_strcmp:

.loop:
    mov al, [rdi]
    mov bl, [rsi] 

    cmp al, bl
    jne .end

    cmp al, 0
    je .end

    inc rdi
    inc rsi
    jmp .loop

.end:
    movzx eax, al
    movzx ebx, bl
    sub eax, ebx 
    ret
