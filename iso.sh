#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/bados.kernel isodir/boot/bados.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "badOS" {
	multiboot /boot/bados.kernel
}
EOF
grub-mkrescue -o bados.iso isodir
