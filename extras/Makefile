# SPDX-License-Identifier: GPL-2.0
#
# extras/Makefile
#
# Makefile for the extras directory.
#
# Most of the targets are used to build 
# and run the docker image for testing the kernel
# on environments that are not supported by the
# build system. It also makes it so that the
# entire build is contained within the docker so 
# that if you screw up, you can always restart the container.

DOCKER-ARCH = linux/$(shell uname -m)

# check docker
ifeq ($(shell docker --version),)
$(error "Docker is not installed")
endif

ifeq ($(shell uname),Darwin)
	MAX-CPU = $(shell sysctl -n hw.ncpu)
endif


ifeq ($(shell uname), Linux)
	MAX-CPU = $(shell nproc)
endif

build-docker:
	@docker build --platform $(DOCKER-ARCH) -t linux-dev extras/.

run-docker:
	@sudo docker run -it --privileged --cap-add SYS_ADMIN --cpus=$(MAX-CPU) --platform $(DOCKER-ARCH) -v .:/linux -v ~/Documents/busybox:/busybox linux-dev
