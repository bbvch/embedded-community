# C++20 Modules Test

This repository hosts scripts/tools/code to experiment with the C++20 modules. The presentation coming out of these experiments can be found at [`presentation/cpp20_modules.pdf`](./presentation/cpp20_modules.pdf).

## Getting started

To have the container ready for experimenting with modules, the latest version of CMake and a recent version of Ninja needs to be installed. Use the accompanying [`Dockerfile`](./Dockerfile) for this purpose. With VS-Code just let it open the folder in the container.

The Dockerfile installs on top of a Ubuntu 22.04:

- CMake 3.28.1
- Ninja 1.11.1
- Clang-17 (official Debian package)
- Clang-18 (LLVM snapshot) (see ["LLVM Debian/Ubuntu nightly packages"][2])

## Examples

### Example 1

Find the code at [src/example1](./src/example1/).

This is a very basic project with two (CMake) libraries (`libfoo` and `libbar`) exporting their code as modules (`foo` and `bar`, respectively). The main program (`main`) is then importing those modules and runs its functions. Note that the `foo` module is even split into two files.


### Example 2

Find the code at [src/example2](./src/example2/).

This contains two applications actually. This is simulating the case where a very costly header is to be included. Essentially the costly header just includes

```c++
#include <bits/stdc++.h>
```

which - supposedly - includes virtually all header offered by the standard library. This takes quite some time. In the header implementation each file including this file takes long to process while in the module implementation that's - apparently - not the case.


### Example 3

Find the code at [src/example3](./src/example3/).

This example showcases the approach as used in the Infitinity open source project (see [GitHub repo][1]):

- each class/collection of functions is its own module
- each module consists of an implementation file (`.cpp`) and a module interface file (`.cppm`)

So essentially it's like: one file = one module (even though technically speaking two files: cpp and cppm).


### Example 4

Find the code at [src/example4](./src/example4/).

This example showcases the approach as used in the Raytracing tutorials open source project (see [GitHub repo][3]):

- each class/collection of functions is located in a dedicated file (`.cppm`)
- all classes belonging to the same library are put into a single module
- the individual files contributing to the module use partitions to build up the module
- there's on dedicated file exporting all the partitions
- some partitions can only be used internally

This seems to be the more natural transformation of an existing library.


[1]: https://github.com/infiniflow/infinity
[2]: https://apt.llvm.org/
[3]: https://github.com/pjmlp/RaytracingWeekend-CPP/tree/main/OneWeekend
