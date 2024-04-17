add_executable(main_example3
    main.cpp)

target_link_libraries(main_example3
    PRIVATE
        libOneModulePerFile::libOneModulePerFile
)
