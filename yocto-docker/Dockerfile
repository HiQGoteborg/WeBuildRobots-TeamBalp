FROM gmacario/build-yocto

#This image will be insanly big!
RUN mkdir -p ~/shared && sudo chown build.build ~/shared
USER build
WORKDIR /home/build/shared
RUN git clone -b jethro git://git.yoctoproject.org/poky
WORKDIR /home/build/shared/poky
RUN . ./oe-init-build-env ~/shared/build-test01

RUN git clone -b jethro git://git.openembedded.org/meta-openembedded
RUN git clone -b jethro git://git.yoctoproject.org/meta-raspberrypi
WORKDIR /home/build/shared/build-test01

ENV PATH /home/build/shared/poky/scripts:/home/build/shared/poky/bitbake/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
ENV BUILDDIR /home/build/shared/build-test01

COPY local.conf /home/build/shared/build-test01/conf/local.conf
COPY bblayers.conf /home/build/shared/build-test01/conf/bblayers.conf
RUN sudo chown -R build.build /home/build/shared/build-test01
RUN bitbake rpi-hwup-image
