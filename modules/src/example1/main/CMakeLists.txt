add_executable(main_example1
    main.cpp)

target_link_libraries(main_example1
    PRIVATE
        libfoo
        libbar
)
