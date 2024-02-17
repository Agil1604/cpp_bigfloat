set(SOURCE_LIB bigfloat.cpp bigfloat_methods.cpp)

add_library(bigfloat STATIC ${SOURCE_LIB})

add_library(my_pi STATIC my_pi.cpp)