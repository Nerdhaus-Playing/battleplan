
add_executable(battleplan
	src/main.cpp
)

target_link_libraries(battleplan PUBLIC
	parser
)

