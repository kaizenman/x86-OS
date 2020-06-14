ENTRY(_start)

SECTIONS
{
    . = 1M;

    .text BLOCK(4K) : ALIGN(4K)
    {
        *(.multiboot)
        *(.text*)
        *(.rodata)
    }

    .data BLOCK(4K) : ALIGN(4K)
    {
        start_ctors = .;
        end_ctors = .;
        
        *(.data)

    }

    .bss BLOCK(4K) : ALIGN(4K)
    {
        *(.COMMON)
        *(.bss)
    }

    /DISCARD/ : 
    { 
        *(.fini_array*) *(.comment) 
    }
}