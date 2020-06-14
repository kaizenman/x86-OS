GCCPARAMS = -m32 -Iinclude -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings
LDPARAMS = -melf_i386

boot.o : boot.s 
		i686-elf-as -o boot.o boot.s

kernel.o : kernel.cpp
		i686-elf-g++ -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -c kernel.cpp -o kernel.o

kernel.bin : linker.ld kernel.o boot.o
		i686-elf-g++ -ffreestanding -O2 -nostdlib -T linker.ld kernel.o boot.o -o kernel.bin

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
		rm -f boot.o
		rm -f boot.bin
		rm -f kernel.bin
		rm -f kernel.iso
		rm -f kernel.o
		