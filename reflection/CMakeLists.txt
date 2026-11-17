cmake_minimum_required(VERSION 3.25)
project(reflection LANGUAGES CXX)

find_package(nlohmann_json CONFIG REQUIRED)

add_executable(reflection main.cpp)
target_link_libraries(reflection PRIVATE nlohmann_json::nlohmann_json)
set_target_properties(reflection PROPERTIES
    CXX_STANDARD 26
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
target_compile_options(reflection PRIVATE -freflection)
