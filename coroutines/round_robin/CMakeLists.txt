PROJECT(round_robin)

SET(CMAKE_CXX_STANDARD 20)

ADD_EXECUTABLE(${PROJECT_NAME}
    coro_promise.h
    coro_promise.cpp
    coro_scheduler.h
    coro_scheduler.cpp
    definitions.h
    example_task.h
    example_task.cpp
    schedule_next_awaiter.h
    schedule_next_awaiter.cpp
    main.cpp
)
