add_executable(main main.cpp)

target_link_libraries(main PRIVATE bigfloat)
target_link_libraries(main PRIVATE my_pi)

add_custom_target(calc_pi COMMAND main)

target_include_directories(main PRIVATE
        "${PROJECT_SOURCE_DIR}/lib"
)
