
add_executable(battleplan
	src/main.cpp
	src/ExitAction.cpp
)

target_link_libraries(battleplan PUBLIC
	parser
)

