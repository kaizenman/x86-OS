# x86-OS
Operating system development

## Setup
### Platform
I used WSL for the OS development with Ubuntu 18.04 LTS installed.
### Build a cross-compiler
```
sudo apt install build-essential
sudo apt install bison
sudo apt install flex
sudo apt install libgmp3-dev
sudo apt install libmpc-dev
sudo apt install libmpfr-dev
sudo apt install libcloog-isl-dev
sudo apt install libisl-dev
sudo apt install texinfo
export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"
```
#### Build binutils
```
mkdir src
cd src
wget -c https://ftp.gnu.org/gnu/binutils/binutils-2.34.tar.xz   
tar -xf binutils-2.34.tar.xz  
rm binutils-2.34.tar.xz
mkdir build-binutils
cd build-binutils
../binutils-2.34/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
sudo make install
```
#### Build gcc
```
cd $HOME/src
wget -c https://ftp.gnu.org/gnu/gcc/gcc-10.1.0/gcc-10.1.0.tar.xz
tar -xf gcc-10.1.0.tar.xz
rm gcc-10.1.0.tar.xz
mkdir build-gcc
cd build-gcc
../gcc-x.y.z/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
sudo make install-gcc
sudo make install-target-libgcc

export PATH="$HOME/opt/cross/bin:$PATH"
```
