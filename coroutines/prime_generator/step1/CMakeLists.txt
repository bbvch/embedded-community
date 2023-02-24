PROJECT(prime_generator_step1)

SET(CMAKE_CXX_STANDARD 20)

ADD_EXECUTABLE(${PROJECT_NAME}
	main.cpp
	generator.h
	generator.cpp
)
