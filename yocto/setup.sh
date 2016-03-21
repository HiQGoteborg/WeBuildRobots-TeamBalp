#!/bin/bash
#
#
sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib \
     build-essential chrpath socat libsdl1.2-dev xterm
mkdir yocto
git clone git://git.yoctoproject.org/poky
cd poky
git checkout -b fido origin/fido
git clone git://git.yoctoproject.org/meta-raspberrypi
source oe-init-build-env
