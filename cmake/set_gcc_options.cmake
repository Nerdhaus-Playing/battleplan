



function(set_default_gcc_target_options targetName)
	message("Setting default GCC options for target '${targetName}'")

	if (MINGW)
		target_compile_definitions(${targetName}
			PUBLIC
				__USE_MINGW_ANSI_STDIO
		)
	endif()

	# To see all warning switches: g++ --help=warnings

	target_compile_options(${targetName}
		PRIVATE
			-Wall -Wextra
	)
endfunction()