set(NAME libmodule)

add_library(${NAME})
add_library(${NAME}::${NAME} ALIAS ${NAME})

target_sources(${NAME}
  PUBLIC
    FILE_SET CXX_MODULES FILES
        costlylib.cpp
)
