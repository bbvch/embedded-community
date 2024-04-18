add_library(libfoo)

target_sources(libfoo
    PUBLIC
        FILE_SET CXX_MODULES FILES
            libfoo1.cpp
    PRIVATE
        libfoo2.cpp
)
