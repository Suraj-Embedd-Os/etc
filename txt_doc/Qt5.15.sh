#!/bin/bash

DIR_PATH="/media/toad/Data/"
apt-get update
apt-get upgrade

apt install gcc git bison python gperf pkg-config
apt install make libclang-dev build-essential

cd $DIR_PATH
mkdir -p Qt5.15.4 
cd Qt5.15.4


wget wget http://master.qt.io/archive/qt/5.15/5.15.4/single/qt-everywhere-src-5.15.4.tar.xz
tar xf qt-everywhere-src-5.15.4.tar.xz

wget https://raw.githubusercontent.com/Kukkimonsuta/rpi-buildqt/master/scripts/utils/sysroot-relativelinks.py
chmod +x sysroot-relativelinks.py
./sysroot-relativelinks.py sysroot


cp -r qt-everywhere-src-5.15.4/qtbase/mkspecs/devices/linux-jetson-tk1-g++/ qt-everywhere-src-5.15.4/qtbase/mkspecs/devices/linux-jetson-nano
gedit qt-everywhere-src-5.15.4/qtbase/mkspecs/devices/linux-jetson-nano/qmake.conf


cd  qt-everywhere-src-5.15.4/
./configure -opengl es2 -device linux-jetson-nano -device-option CROSS_COMPILE=/usr/bin/aarch64-linux-gnu- -sysroot $DIR_PATH/Qt5.15.4/sysroot -prefix /usr/local/qt5.15.4 -opensource -confirm-license -skip qtscript -skip wayland -skip qtwebengine -force-debug-info -skip qtdatavis3d -skip qtlocation -nomake examples -make libs -pkg-config -no-use-gold-linker -v 

make
make install

#/home/toad2/Qt/5.15.2/gcc_64/bin
#/home/toad2/Qt/Tools/CMake/bin/cmake

#//sudo ln -sf /usr/local/Qt-5.15.2/bin/qmake /usr/lib/aarch64-linux-gnu/qt5/bin/qmake


#/usr/local/Qt-5.15.2/lib/cmake/Qt5


-system-xcb
-developer-build -opensource -no-gtkstyle -nomake examples -nomake tests
