# Multiboot header
# 0	u32	magic	required
# 4	u32	flags	required (Bits 0-15 requirements, 16-31 - optional features)
# 8	u32	checksum	required
# 12	u32	header_addr	if flags[16] is set
# 16	u32	load_addr	if flags[16] is set
# 20	u32	load_end_addr	if flags[16] is set
# 24	u32	bss_end_addr	if flags[16] is set
# 28	u32	entry_addr	if flags[16] is set
# 32	u32	mode_type	if flags[2] is set
# 36	u32	width	if flags[2] is set
# 40	u32	height	if flags[2] is set
# 44	u32	depth	if flags[2] is set


.set MAGIC, 0x1BADB002
# BIT 0 in the FLAGS - all boot modules loaded along with operating system must be aligned on page (4KB) boundaries
.set ALIGN, 1 << 0
# BIT 1 in the FLAGS - information on available memory of the multiboot structure must be included
.set MEMINFO, 1 << 1 
.set FLAGS, ALIGN | MEMINFO
# CHECKSUM value when added to the magic + flags, must have a 32-bit unsigned sum of zero
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
# align at a 32-bit boundary
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section bss
.align 16
stack_bottom:
.skip 16384
stack_top:

.section .text
.global _start 		         # make our label "_start" visible to the outside
.type _start, @function
.global callConstructors
.type callConstructors, @function
_start:
    mov $stack_top, %esp
    call callConstructors
    call kernelMain

_stop:
    cli
    hlt
    jmp _stop



   
   

