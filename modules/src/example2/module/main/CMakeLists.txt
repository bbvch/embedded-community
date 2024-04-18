add_executable(main_example2module
    main.cpp
    main1.cpp
    main2.cpp
    main3.cpp
    main4.cpp
    main5.cpp)

target_link_libraries(main_example2module
    PRIVATE
        libmodule::libmodule
)
