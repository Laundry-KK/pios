;;kernel.asm
bits 32			;nasm directive - 32 bit
section .text

global start
extern kmain	        ;kmain is defined in the PiKern file

start:
  cli 			;block interrupts
  mov esp, stack_space	;set stack pointer
  call kmain
  hlt		 	;halt the CPU(define later)

section .bss
resb 8192		;8KB for stack
stack_space: