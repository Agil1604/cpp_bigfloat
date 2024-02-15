add_executable(my_test test.cpp)

add_custom_target(start_test COMMAND my_test)

target_link_libraries(my_test PRIVATE gtest_main bigfloat)

target_include_directories(my_test PRIVATE
        "${PROJECT_SOURCE_DIR}/lib"
)
