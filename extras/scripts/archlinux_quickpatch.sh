# SPDX-License-Identifier: GPL-2.0
#
# extras/scripts/archlinux_quickpatch.sh
#
# 0x424 - July 2024
#
# This script is used to quickly patch an Arch Linux installation with the
# latest kernel image. This is an quick and dirty way to update the kernel with
# the built image.
#
# On your host run a http server in the same directory as the `Image` and
# `Image.gz` files. You can do this by running the following command:
#
# python3 -m http.server
# 
# Then copy the lines below into a serial with bash. You will need to be root
# since this script will be writing to the boot partition.
#
# If you brick your device, you can always use the recovery image to restore
# the device to a working state. To do this point GRUB or your bootloader to
# the recovery image located in /boot/Image.bak and /boot/Image.gz.bak.

cd /root
curl 192.168.64.1:8000/Image --output /tmp/Image
curl 192.168.64.1:8000/Image.gz --output /tmp/Image.gz
cd /tmp
chmod +x Image
chmod +x Image.gz
cp /boot/Image /boot/Image.bak
cp /boot/Image.gz /boot/Image.gz.bak
mv Image /boot/Image
mv Image.gz /boot/Image.gz
reboot
