set(libname probability)

set(srclist
        Probability.cpp
        Probability.h)

add_library(${libname} STATIC ${srclist})
target_include_directories(${libname} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

unset(libname)