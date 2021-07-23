GCCPARAMS = -m32 -Iinclude -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings
ASPARAMS = --32
OBJECTS = boot.o gdt.o interrupts.o interruptstubs.o  port.o Console.o kernel.o 
LDPARAMS = -melf_i386

AS = i686-elf-as 
CC = i686-elf-g++
LD = i686-elf-ld

%.o: %.s
	$(AS) $(ASPARAMS) -o $@ $<

%.o: %.cpp
	$(CC) $(GCCPARAMS) -o $@ -c $<

kernel.bin : linker.ld $(OBJECTS)
	$(LD) $(LDPARAMS) -T $< -o $@ $(OBJECTS)

kernel.iso : kernel.bin
		mkdir iso
		mkdir iso/boot
		cp -f kernel.bin iso/boot/kernel.bin
		mkdir iso/boot/grub
		printf "set timeout=1\n" > iso/boot/grub/grub.cfg
		printf "set default=0\n" >> iso/boot/grub/grub.cfg
		printf "\n" >> iso/boot/grub/grub.cfg
		printf "menuentry \"x86-OS\" {\n" >> iso/boot/grub/grub.cfg
		printf "    multiboot /boot/kernel.bin\n" >> iso/boot/grub/grub.cfg
		printf "    boot\n" >> iso/boot/grub/grub.cfg
		printf "}\n" >> iso/boot/grub/grub.cfg
		grub-mkrescue -d /usr/lib/grub/i386-pc -o kernel.iso iso 
		rm -rf iso
		
# Custom bootloader
# boot.bin : boot.o
#		i686-elf-ld -o boot.bin --oformat binary -e _start boot.o

run: kernel.iso
		qemu-system-i386 -cdrom kernel.iso -boot d

.PHONY : clean
clean :
		rm -f *.o
		rm -f boot.bin
		rm -f kernel.bin
		rm -f kernel.iso
		