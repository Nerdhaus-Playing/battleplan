include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)


cmake_minimum_required(VERSION 3.12)

project(aclt VERSION ${CONAN_PACKAGE_VERSION}
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

if(${BUILD_WITH_DEMO})
	message(STATUS "Building with demo")
	add_subdirectory(demo)

else()
	message(STATUS "Skipping demo")
endif()

if(${BUILD_WITH_TESTS})
	message(STATUS "Building with tests")
	add_subdirectory(tests)
else()
	message(STATUS "Skipping tests")
endif()



install(TARGETS aclt
	DESTINATION bin
)