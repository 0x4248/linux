# SPDX-License-Identifier: GPL-2.0
#
# extras/Dockerfile
#
# 0x424 - July 2024
#
# Docker file for creating a insulated build environment
# for the Linux kernel. This is a Debian based image.

FROM debian:latest

RUN apt-get update

# Required packages for building the kernel
RUN apt-get install -y \
    fakeroot \
    build-essential \
    ncurses-dev \
    xz-utils \
    libssl-dev \
    bc \
    flex \
    libelf-dev \
    bison \
    cpio


# Handy tools just in case
RUN apt-get install -y git fish vim nano 

WORKDIR /linux 

CMD ["/bin/fish"]