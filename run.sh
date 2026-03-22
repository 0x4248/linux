qemu-system-x86_64 \
  -kernel arch/x86_64/boot/bzImage \
  -initrd initramfs/initramfs.cpio.gz \
  -m 512M \
  -vga cirrus \
  -append "console=ttyS0,115200n8 console=tty0 fbcon=map:0 video=vesafb:mtrr:3,ywrap,1024x768-16 root=/dev/ram rdinit=/init loglevel=7"