# SPDX-License-Identifier: GPL-2.0
#
# drivers/video/logo/processppm.sh
#
# 0x424 - July 2024
#
# Takes in tmp.ppm and converts it the correct format for the linux logo. To use
# this tool you will need netpbm. On debian you can install this by running:
#
# apt install netpbm

ppmquant 224 tmp.ppm > tmp2.ppm
pnmtoplainpnm tmp2.ppm > logo_linux_clut224.ppm
echo done