include(${PROJECT_SOURCE_DIR}/cmake/set_gcc_options.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/set_msvc_options.cmake)




function(set_default_target_options targetName)

	set_target_properties(${targetName}
		PROPERTIES
			# Define the C++ standard:
			CXX_STANDARD 17

			# Don't fall back to an earlier standard:
			CXX_STANDARD_REQUIRED YES

			# Don't allow C++ extension:
			CXX_EXTENSIONS OFF
	)

	if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
			set_default_gcc_target_options(${targetName})
		elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
			message(FATAL_ERROR "Clang is not supported yet, write an e-mail to the developer of this repo nerdhaus.playing@gmail.com")
		endif()
	elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
		set_default_msvc_target_options(${targetName})
	endif()
endfunction()