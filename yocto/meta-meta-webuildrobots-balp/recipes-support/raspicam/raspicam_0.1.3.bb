SUMMARY = "RaspiCam: C++ API for using Raspberry camera (with OpenCV)"
HOMEPAGE = "http://www.uco.es/investiga/grupos/ava/node/40"
SECTION = "libs"

DEPENDS = "opencv userland"

LICENSE = "BSD-4-Clause"
LIC_FILES_CHKSUM = "file://src/raspicam.cpp;beginline=1;endline=36;md5=13bee828b05cd78284445601d1814a02"

SRC_URI = "https://sourceforge.net/projects/raspicam/files/raspicam-0.1.3.zip"
SRC_URI[md5sum] = "1c6fef67aeaa7828bcde899e9873986e"
SRC_URI[sha256sum] = "cfdb5b6709cdf0defc218cd6e7bef15ab23df1a09c3d265245a63f44ca4a7a50"

#SRC_URI = "http://downloads.sourceforge.net/project/raspicam/raspicam-0.1.3.zip?r=https%3A%2F%2Fsourceforge.net%2Fprojects%2Fraspicam%2Ffiles%2F&ts=1457827924&use_mirror=netassist"

inherit cmake
EXTRA_OECMAKE += "-DBUILD_SHARED_LIBS=OFF -DBUILD_UTILS=OFF"
FILES_${PN} = "${includedir} ${libdir}"
FILES_${PN}-dev = "${base_libbir}/cmake/"
