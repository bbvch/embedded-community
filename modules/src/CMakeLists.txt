# basic example using modules
add_subdirectory(example1)

# compile time optimization using modules
add_subdirectory(example2)

# splitting large library in number of modules
# (approach followed by https://github.com/infiniflow/infinity)
add_subdirectory(example3)

# splitting large library into one module consisting of multiple partitions
# (approach followed by https://github.com/pjmlp/RaytracingWeekend-CPP/tree/main/OneWeekend)
add_subdirectory(example4)
