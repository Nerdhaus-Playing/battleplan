
function(set_default_msvc_target_options targetName)
	message("Setting default MSVC options for target '${targetName}")

	# CMake appends /W3 by default, and having /W3 followed by /W4 will result in
	# cl : Command line warning D9025 : overriding '/W3' with '/W4'.  Since this is
	# a command line warning and not a compiler warning, it cannot be suppressed except
	# by fixing the command line.

	string(REGEX REPLACE " /W[0-4]" " /W4" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
	string(REGEX REPLACE " /W[0-4]" " /W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

	target_compile_definitions(${targetName}
		PRIVATE
			_CRT_SECURE_NO_WARNINGS
	)

	target_compile_options(${targetName}
		PRIVATE
			/permissive-
	)
endfunction()