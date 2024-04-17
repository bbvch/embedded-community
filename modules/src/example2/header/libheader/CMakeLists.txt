set(NAME libheader)

add_library(${NAME})
add_library(${NAME}::${NAME} ALIAS ${NAME})

target_sources(${NAME}
    PRIVATE
        include/costlylib.h
        src/costlylib.cpp
)

target_include_directories(${NAME}
    PUBLIC
        include
)
