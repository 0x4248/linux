qemu-system-x86_64 \
  -kernel arch/x86_64/boot/bzImage \
  -initrd initramfs/initramfs.cpio \
  -append "console=ttyS0 console=tty0 init=/bin/sh video=640x480" \
  -serial mon:stdio \
  -device virtio-gpu-pci \
  -display sdl 