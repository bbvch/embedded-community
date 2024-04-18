add_executable(main_example4
    main.cpp)

target_link_libraries(main_example4
    PRIVATE
        libModuleWithPartitions::libModuleWithPartitions
)
