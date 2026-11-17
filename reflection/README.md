# C++ reflection example

This example uses C++26 reflection to serialize structs to JSON with
[nlohmann/json](https://github.com/nlohmann/json). In `main.cpp`, `to_json`
converts values supported by the JSON library directly and recursively visits
the non-static data members of other types. An `std::optional` is serialized
as its contained value or `null`.

The program prints two `User` objects: one without a student and one with a
nested `Student` containing grades. Reflection uses unchecked access, so the
student's private `secret` member is included in the JSON output too. This is
a demonstration rather than a serializer suitable for sensitive data.

## Build and run

The project requires CMake 3.25 or newer, nlohmann/json, and a compiler with
C++26 reflection support. CMake enables GCC's `-freflection` option.

Open this directory in VS Code and select **Dev Containers: Reopen in Container**.
The container uses GCC 16.2.0, the latest stable release at setup time. Its
version is pinned in `.devcontainer/Dockerfile`; update it when needed. The
container also installs CMake, Ninja, and nlohmann/json.

Build and run inside the container:

```sh
cmake -S . -B build -G Ninja
cmake --build build
./build/reflection
```
