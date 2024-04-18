set(NAME libModuleWithPartitions)

add_library(${NAME})
add_library(${NAME}::${NAME} ALIAS ${NAME})

target_sources(${NAME}
    PUBLIC
        FILE_SET CXX_MODULES FILES
            libModuleWithPartitions.cppm
            homer.cppm
            marge.cppm
            bart.cppm
            lisa.cppm
            person.cppm
)
