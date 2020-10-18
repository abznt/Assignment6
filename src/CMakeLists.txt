set(targetName main)

add_subdirectory(probability)

add_executable(${targetName} main.cpp)
target_link_libraries(${targetName} probability)

unset(targetName)