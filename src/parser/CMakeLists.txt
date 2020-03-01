
add_library(parser 
	src/commandparser.cpp
)

target_include_directories(parser
	PUBLIC include
)
