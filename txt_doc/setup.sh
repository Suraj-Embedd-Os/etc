#!/bin/bash

LIB_PATH="/media/toad/Data/Chetu_Downloads"
cd $LIB_PATH
mkdir -p qt5nano 
cd qt5nano

sudo apt update
sudo apt upgrade

sudo apt install -y '.*libxcb.*' libxrender-dev libxi-dev libfontconfig1-dev libudev-dev libgles2-mesa-dev libgl1-mesa-dev gcc git bison python gperf pkg-config make libclang-dev build-essential




wget https://releases.linaro.org/components/toolchain/binaries/latest-5/aarch64-linux-gnu/gcc-linaro-5.5.0-2017.10-x86_64_aarch64-linux-gnu.tar.xz
tar xfv gcc-linaro-5.5.0-2017.10-x86_64_aarch64-linux-gnu.tar.xz 
export PATH=$PATH:$LIB_PATH/qt5nano/gcc-linaro-5.5.0-2017.10-x86_64_aarch64-linux-gnu/bin

wget https://download.qt.io/official_releases/qt/6.2/6.2.4/single/qt-everywhere-src-6.2.4.tar.xz
tar xf qt-everywhere-src-6.2.4.tar.xz

wget https://raw.githubusercontent.com/Kukkimonsuta/rpi-buildqt/master/scripts/utils/sysroot-relativelinks.py
chmod +x sysroot-relativelinks.py
./sysroot-relativelinks.py sysroot

#cp -r qt-everywhere-src-5.15.0/qtbase/mkspecs/devices/linux-jetson-tk1-g++/ qt-everywhere-src-5.15.0/qtbase/mkspecs/devices/linux-jetson-nano
#gedit qt-everywhere-src-5.15.0/qtbase/mkspecs/devices/linux-jetson-nano/qmake.conf


mkdir qt5buid 
cd qt5build
../qt-everywhere-src-5.15.0/configure -opengl es2 -device linux-jetson-nano -device-option CROSS_COMPILE=/media/toad/Data/Chetu_Downloads/QT5.15/gcc-linaro-5.5.0-2017.10-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu- -sysroot /media/toad/Data/Chetu_Downloads/QT5.15/sysroot -prefix /usr/local/qt5 -opensource -confirm-license -skip qtscript -skip wayland -skip qtwebengine -force-debug-info -skip qtdatavis3d -skip qtlocation -nomake examples -make libs -pkg-config -no-use-gold-linker -v
make -j4
make install

