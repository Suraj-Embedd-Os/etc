#!/bin/bash
apt update
apt upgrade

apt install gcc git bison python gperf pkg-config
apt install make libclang-dev build-essential

dir_name=$1

mkdir -p /opt/$dir_name
chown toad2:toad2 /opt/$dir_name
cd /opt/$dir_name

if [[ ! -d gcc-linaro-5.5.0-2017.10-x86_64_aarch64-linux-gnu ]]
then
	wget https://releases.linaro.org/components/toolchain/binaries/latest-5/aarch64-linux-gnu/gcc-linaro-5.5.0-2017.10-x86_64_aarch64-linux-gnu.tar.xz
	tar xf gcc-linaro-5.5.0-2017.10-x86_64_aarch64-linux-gnu.tar.xz 
fi
export PATH=$PATH:/opt/qt5jnano/gcc-linaro-5.5.0-2017.10-x86_64_aarch64-linux-gnu/bin


rm -rf qt-everywhere-src*
wget https://download.qt.io/official_releases/qt/5.15/5.15.0/single/qt-everywhere-src-5.15.0.tar.xz
tar xf qt-everywhere-src-5.15.0.tar.xz

cd /opt/qt5jnano

sshpass -p "86yxfURVtbA5" rsync -avz toad@192.168.60.207:/lib sysroot
sshpass -p "86yxfURVtbA5" rsync -avz toad@192.168.60.207:/usr/include sysroot/usr
sshpass -p "86yxfURVtbA5" rsync -avz toad@192.168.60.207:/usr/lib sysroot/usr

if [[ ! -f sysroot-relativelinks.py ]]
then 
	wget https://raw.githubusercontent.com/Kukkimonsuta/rpi-buildqt/master/scripts/utils/sysroot-relativelinks.py
	chmod +x sysroot-relativelinks.py
fi

./sysroot-relativelinks.py sysroot

cd /opt/$dir_name
cp -r qt-everywhere-src-5.15.0/qtbase/mkspecs/devices/linux-jetson-tk1-g++/ qt-everywhere-src-5.15.0/qtbase/mkspecs/devices/linux-jetson-nano
cp /home/toad2/Qt5/qmake.conf  qt-everywhere-src-5.15.0/qtbase/mkspecs/devices/linux-jetson-nano/

mkdir qt5buid 
cd qt5buid

../qt-everywhere-src-5.15.0/configure -opengl es2 -device linux-jetson-nano -device-option CROSS_COMPILE=/opt/$dir_name/gcc-linaro-5.5.0-2017.10-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu- -sysroot /opt/qt5jnano/sysroot -prefix /usr/local/$dir_name -opensource -confirm-license -skip qtscript -skip wayland -skip qtwebengine -force-debug-info -skip qtdatavis3d -skip qtlocation -nomake examples -make libs -pkg-config -no-use-gold-linker -v
make -j4
make install

cd /opt/qt5jnano

sshpass -p "86yxfURVtbA5" rsync -avz ./sysroot/usr/local/$dir_name toad@192.168.60.207:/media/toad/Data/build_dir/
