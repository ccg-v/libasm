global ft_strlen

section .text

ft_strlen:
	xor rax, rax

.loop:
	cmp byte [rdi], 0
	je .end

	inc rax
	inc rdi
	jmp .loop

.end:
	ret
