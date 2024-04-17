FROM ubuntu:22.04

ARG USERNAME=user
ARG USER_UID=10000
ARG USER_GID=10001

ARG CMAKE_VERSION=3.28.1
ARG NINJA_VERSION=1.11.1

RUN apt-get update -y \
    && apt-get install -y wget lsb-release software-properties-common

WORKDIR /pkg_installation

# install Clang-17 and Clang-18
# (LLVM snapshot packages)
RUN wget https://apt.llvm.org/llvm.sh
RUN chmod u+x llvm.sh

RUN ./llvm.sh 17
RUN ./llvm.sh 18

# choose Clang-17 as default
ENV CXX=clang++-17

RUN apt-get update -y \
    && apt-get install -y \
        clang-17 clang-18 clang-tidy-17 clang-format-17 clang-tidy-18 clang-format-18

# install Python and further development tools
RUN apt-get update -y \
    && apt-get install -y cmake python3 git sudo \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# install CMake 3.28.1
# (pre-built packages by Kitware)
RUN wget https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}-linux-x86_64.sh
RUN chmod u+x cmake-${CMAKE_VERSION}-linux-x86_64.sh
RUN mkdir -p /opt/kcmake-${CMAKE_VERSION}
RUN ./cmake-${CMAKE_VERSION}-linux-x86_64.sh --skip-license --exclude-subdir --prefix=/opt/kcmake-${CMAKE_VERSION}
RUN ln -s /opt/kcmake-${CMAKE_VERSION}/bin/cmake /usr/bin/kcmake

# build and install Ninja 1.11.1
RUN wget https://github.com/ninja-build/ninja/archive/refs/tags/v${NINJA_VERSION}.tar.gz -O ninja-${NINJA_VERSION}.tar.gz
RUN tar -xvzf ninja-${NINJA_VERSION}.tar.gz
WORKDIR /pkg_installation/ninja-${NINJA_VERSION}
RUN mkdir -p build-cmake
RUN kcmake -Bbuild-cmake
RUN kcmake --build build-cmake
RUN kcmake --install build-cmake --prefix /opt/ninja-${NINJA_VERSION}
RUN ln -s /opt/ninja-${NINJA_VERSION}/bin/ninja /usr/bin/ninja

RUN groupadd --gid ${USER_GID} ${USERNAME} \
    && useradd --uid ${USER_UID} --gid ${USER_GID} -m ${USERNAME} -s /usr/bin/bash

USER ${USERNAME}
WORKDIR /home/user
