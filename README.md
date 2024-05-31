# Yori-OS
A toy system on riscv64.
# install tools
## riscv-gnu-toolchain
Install [riscv-gnu-toolchain](https://github.com/riscv-collab/riscv-gnu-toolchain). This will take a long time.
```shell
git clone https://github.com/riscv-collab/riscv-gnu-toolchain
```
build and install (on Ubuntu or Debian)
```shell
$ cd riscv-gnu-toolchain
$ sudo apt install autoconf automake autotools-dev curl python3 python3-pip libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf $ libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev libslirp-dev
$ mkdir build && cd build
$ ../newlib/configure --host=riscv64-unknown-elf --prefix=/path/to/install # change here!
$ make
$ make install # if error, use sudo!
$ export PATH="$PATH:/path/to/install" # change here! you can add it to ~/.bashrc
```
## others
```shell
sudo apt install git make vim gdb-multiarch qemu-system-misc
```
# run
```shell
make run
```
# TODO