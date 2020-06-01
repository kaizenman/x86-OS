GPPPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
ASPARAMS = --32

LDPARAMS = -melf_i386

objects = loader.o gdt.o kernel.o

%.o: %.cpp
	i686-elf-g++ $(GPPPARAMS) -o $@ -c $<
	
%.o: %.s
	i686-elf-as $(ASPARAMS) -o $@ $<
	
mykernel.bin: linker.ld $(objects)
	i686-elf-ld $(LDPARAMS) -T $< -o $@ ${objects}

mykernel.iso: mykernel.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp $< iso/boot/
	echo 'set timeout=15' > iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	echo 'menuentry "My Operating System" {' >> iso/boot/grub/grub.cfg
	echo '   multiboot /boot/mykernel.bin' >> iso/boot/grub/grub.cfg
	echo '   boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=$@ iso
	rm -rf  iso

run: mykernel.iso
	qemu-system-i386 -cdrom mykernel.iso
clean:
	rm -f *.o
	rm -f *.bin
	rm -f *.iso
