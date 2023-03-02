PROJECT(non_blocking_reader)

SET(CMAKE_CXX_STANDARD 20)

ADD_EXECUTABLE(${PROJECT_NAME}
	main.cpp
	read_awaiter.h
	read_awaiter.cpp
	read_promise.h
	read_promise.cpp
	read_result.h
	read_result.cpp
	read_stub.h
	read_stub.cpp
	read_test.h
	read_test.cpp
)