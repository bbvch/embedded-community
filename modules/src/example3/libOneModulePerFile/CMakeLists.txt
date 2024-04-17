set(NAME libOneModulePerFile)

add_library(${NAME}
    fibonacci.cpp
    someMath.cpp
)
add_library(${NAME}::${NAME} ALIAS ${NAME})

target_sources(${NAME}
    PUBLIC
        FILE_SET CXX_MODULES FILES
            factorial.cppm
            fibonacci.cppm
            someMath.cppm
)
