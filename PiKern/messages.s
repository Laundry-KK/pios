;;kernel.asm
bits 64			;nasm directive - 64 bit
section .text

global start
extern pimain	        ;pimain is defined in the c file

start:
  cli 			;block interrupts
  mov esp, stack_space	;set stack pointer
  call pimain
  hlt		 	;halt the CPU

section .bss
resb 8192		;8KB for stack
stack_space:
