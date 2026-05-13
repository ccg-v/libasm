default rel

global  ft_strdup
extern  ft_strlen
extern  malloc

section .text

ft_strdup:
	push rbx
	push r12

	mov rbx, rdi

	call ft_strlen WRT ..plt

	inc rax

	mov rdi, rax
	call malloc WRT ..plt

	cmp rax, 0		; test rax, rax
	jz .fail

	mov r12, rax

	mov rsi, rbx
	mov rdi, r12

.copy_loop:
	mov dl, [rsi]
	mov [rdi], dl

	cmp dl, 0		; test dl, dl
	jz .done

	inc rsi
	inc rdi
	jmp .copy_loop

.done:
	mov rax, r12

	pop r12
	pop rbx
	ret

.fail:
	xor rax, rax

	pop r12
	pop rbx
	ret
