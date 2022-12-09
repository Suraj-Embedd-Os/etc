#!/bin/bash
apt update
apt upgrade

apt install gcc git bison python gperf pkg-config
apt install make libclang-dev build-essential

mkdir -p /opt/qt5tx
chown toad2:toad2 /opt/qt5tx
cd /opt/qt5tx/

wget https://releases.linaro.org/components/toolchain/binaries/latest-5/aarch64-linux-gnu/gcc-linaro-5.5.0-2017.10-x86_64_aarch64-linux-gnu.tar.xz
tar xf gcc-linaro-5.5.0-2017.10-x86_64_aarch64-linux-gnu.tar.xz 
export PATH=$PATH:/opt/qt5tx/gcc-linaro-5.5.0-2017.10-x86_64_aarch64-linux-gnu/bin


wget https://download.qt.io/official_releases/qt/5.15/5.15.0/single/qt-everywhere-opensource-src-5.15.0.tar.xz
tar xf qt-everywhere-opensource-src-5.15.4.tar.xz

#sshpass -p "86yxfURVtbA5" rsync -avze toad@192.168.60.207:/lib sysroot
#sshpass -p "86yxfURVtbA5" rsync -avze toad@192.168.60.207:/usr/include sysroot/usr
#sshpass -p "86yxfURVtbA5" rsync -avze toad@192.168.60.207:/usr/lib sysroot/usr

sshpass -p "86yxfURVtbA5" rsync -avz toad@192.168.60.207:/lib sysroot
sshpass -p "86yxfURVtbA5" rsync -avz toad@192.168.60.207:/usr/include sysroot/usr
sshpass -p "86yxfURVtbA5" rsync -avz toad@192.168.60.207:/usr/lib sysroot/usr

wget https://raw.githubusercontent.com/Kukkimonsuta/rpi-buildqt/master/scripts/utils/sysroot-relativelinks.py
chmod +x sysroot-relativelinks.py
./sysroot-relativelinks.py sysroot



#cp -r qt-everywhere-src-5.15.0/qtbase/mkspecs/devices/linux-jetson-tk1-g++/ qt-everywhere-src-5.15.0/qtbase/mkspecs/devices/linux-jetson-nano
#gedit qt-everywhere-src-5.15.0/qtbase/mkspecs/devices/linux-jetson-nano/qmake.conf

#mkdir qt5buid 
cd qt-everywhere-src-5.15.0
./configure -opengl es2 -device linux-jetson-tx1-g++ -device-option CROSS_COMPILE=/opt/qt5tx/gcc-linaro-5.5.0-2017.10-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu- -sysroot /opt/qt5tx/sysroot -prefix /usr/local/qt5.15.0 -opensource -confirm-license -skip qtscript -skip wayland -skip qtwebengine -force-debug-info -skip qtdatavis3d -skip qtlocation -nomake examples -make libs -pkg-config -no-use-gold-linker -v
make -j4
make install

#sshpass -p "86yxfURVtbA5" rsync -avze sysroot/usr/local/qt5jnano root@192.168.16.24:/usr/local

./configure -opengl es2 -device linux-jetson-nano -device-option CROSS_COMPILE=/opt/qt5jnano/gcc-linaro-5.5.0-2017.10-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu- -sysroot /opt/qt5jnano/sysroot/sysroot -prefix /usr/local/qt5.15.4 -opensource -confirm-license -skip qtscript -skip wayland -skip qtwebengine -force-debug-info -skip qtdatavis3d -skip qtlocation -nomake examples -make libs -pkg-config -no-use-gold-linker -v 
