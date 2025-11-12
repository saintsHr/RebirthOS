AS = i686-elf-as
CC = i686-elf-gcc

SRC_C = $(shell find src -type f -name '*.c')
SRC_S = $(shell find src -type f -name '*.s')

OBJ = $(SRC_C:src/%.c=build/%.o) $(SRC_S:src/%.s=build/%.o)

ASFLAGS =
CFLAGS = -Iinclude -std=gnu99 -ffreestanding -O2 -Wall -Wextra
LDFLAGS = -ffreestanding -O2 -nostdlib -lgcc

NAME = os

all: bin/$(NAME).bin
iso: bin/os.iso

clear:
	rm -rf bin
	rm -rf build
	rm -rf isodir

bin/os.iso: bin/$(NAME).bin
	mkdir -p isodir/boot/grub
	cp bin/$(NAME).bin isodir/boot/$(NAME).bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o bin/$(NAME).iso isodir

run:
	qemu-system-i386 -cdrom bin/$(NAME).iso -serial stdio

build/%.o: src/%.s
	mkdir -p $(dir $@)
	$(AS) $< -o $@

build/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

bin/os.bin: $(OBJ)
	mkdir -p bin
	$(CC) -T linker.ld -o $@ $(LDFLAGS) $^