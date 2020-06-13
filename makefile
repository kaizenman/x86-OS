boot.o : boot.s 
		i686-elf-as -o boot.o boot.s

kernel.o : kernel.c
		i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra 

kernel.bin : kernel.o boot.o
		i686-elf-gcc -T linker.ld -o kernel.bin -ffreestanding -nostdlib -O2 -Wall boot.o kernel.o -lgcc


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
		
# Custom bootloader
# boot.bin : boot.o
#		i686-elf-ld -o boot.bin --oformat binary -e _start boot.o

run: kernel.iso
		qemu-system-i386 -cdrom kernel.iso -boot d

.PHONY : clean
clean :
		rm -f boot.o
		rm -f boot.bin
		rm -rd iso