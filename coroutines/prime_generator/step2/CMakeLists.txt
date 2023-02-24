PROJECT(prime_generator_stepr2)

SET(CMAKE_CXX_STANDARD 20)

ADD_EXECUTABLE(${PROJECT_NAME}
	main.cpp
	generator.h
	generator.cpp
	printer.h
	printer.cpp
)
