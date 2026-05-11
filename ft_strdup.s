default rel

global  ft_strdup
extern  ft_strlen
extern  malloc

section .text

ft_strdup:
	; ----------------------------
	; Preserve callee-saved regs
	; ----------------------------
	push rbx
	push r12

	; ----------------------------
	; rbx = original string (s1)
	; ----------------------------
	mov rbx, rdi

	; ----------------------------
	; length = ft_strlen(s1)
	; ----------------------------
	call ft_strlen WRT ..plt		; rax = length

	inc rax					; +1 for '\0'

	; ----------------------------
	; malloc(length + 1)
	; ----------------------------
	mov rdi, rax
	call malloc WRT ..plt

	; ----------------------------
	; check malloc result
	; ----------------------------
	test rax, rax
	je .fail

	; ----------------------------
	; save allocated pointer
	; ----------------------------
	mov r12, rax

	; ----------------------------
	; setup copy pointers
	; ----------------------------
	mov rsi, rbx            ; source
	mov rdi, r12            ; destination

.copy_loop:
	mov dl, [rsi]          ; 1-byte register NOT tied to rax
	mov [rdi], dl

	test dl, dl
	je .done

	inc rsi
	inc rdi
	jmp .copy_loop

.done:
	mov rax, r12            ; return malloc pointer

	pop r12
	pop rbx
	ret

.fail:
	xor rax, rax

	pop r12
	pop rbx
	ret
