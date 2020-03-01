include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)


cmake_minimum_required(VERSION 3.12)

project(battleplan VERSION ${CONAN_PACKAGE_VERSION}
                  DESCRIPTION "Commandline tool for arbitrary environments"
                  LANGUAGES CXX)

conan_basic_setup(NO_OUTPUT_DIRS)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(OUTPUT_DIR ${PROJECT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})

set(CMAKE_CXX_STANDARD 17)

#add the necessary targets
 
set(Boost_USE_STATIC_LIBS TRUE)

find_package(Boost COMPONENTS filesystem system REQUIRED)

add_subdirectory(src)



#install(TARGETS battleplan
	#DESTINATION bin
#)