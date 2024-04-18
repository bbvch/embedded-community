add_library(libbar)

target_sources(libbar
  PUBLIC
    FILE_SET CXX_MODULES FILES
        libbar.cpp
)
