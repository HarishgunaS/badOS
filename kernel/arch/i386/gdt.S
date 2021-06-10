.section .text
.global setGDT
.global gdt_start
.global gdt_end
.type setGDT, @function

gdt_start:
//change number of entries here?
gdt_null:
.quad 0
gdt_code:
.quad 0
gdt_data:
.quad 0
gdt_end:

gdtr:
.word 0
.long 0

setGDT:
mov 	%eax, 4(%esp)
mov 	(gdtr + 2), %eax
mov 	%ax, 8(%esp)
mov	(gdtr), %ax
lgdt	(gdtr)
ret


