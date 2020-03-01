
add_library(dllloader
    src/dllloader.cpp
    src/dllloaderimpl.cpp
)

target_link_libraries(dllloader
    Boost::boost
    Boost::filesystem
    Boost::system
)

target_include_directories(dllloader
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)