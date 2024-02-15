add_executable(main main.cpp)

target_link_libraries(main PRIVATE bigfloat)

# Тут прописываются все папки откуда будут подтягиваться header-ы
# Теперь можно писать #include "bigfloat.h" даже при том что они в сильно разных папках
target_include_directories(main PRIVATE
        "${PROJECT_SOURCE_DIR}/lib"
)
