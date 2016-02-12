# This file is designed to help isolate your specific project settings.
# The variable names are predetermined. DO NOT CHANGE the variable names.
# You may change the values of the variables.


# You have a choice. 
# When you add resource files, you may manually add it here.
# Or you may disable manual mode and have the system automatically create the list.
# The downside to automatic mode is that you must remember to regenerate when you add a new file.
# The upside to manual mode is you can get fancy and case for things like Windows/Android/Mac/iOS/Linux.
# CMake officially recommends manual mode.

set(BLURRR_USE_MANUAL_FILE_LISTING_FOR_RESOURCE_FILES TRUE)
set(BLURRR_USE_MANUAL_FILE_LISTING_FOR_SCRIPT_FILES TRUE)

# Resource files
if(BLURRR_USE_MANUAL_FILE_LISTING_FOR_RESOURCE_FILES)

	# Add your user resource files here
	list(APPEND BLURRR_USER_RESOURCE_FILES
		${PROJECT_SOURCE_DIR}/resources/icon.bmp
		${PROJECT_SOURCE_DIR}/resources/swift_logo.png
		${PROJECT_SOURCE_DIR}/resources/VeraMono.ttf

	)
else()
	# We will automatically slurp everything.
	# But you must remember to regenerate every time you add a file.
	set(BLURRR_AUTOMATIC_USER_RESOURCE_FILES_SHOULD_FOLLOW_SYMLINKS TRUE)
	set(BLURRR_AUTOMATIC_USER_RESOURCE_FILES_GLOB_PATTERN "${PROJECT_SOURCE_DIR}/resources/*")
endif()

# Script files
if(BLURRR_USE_MANUAL_FILE_LISTING_FOR_SCRIPT_FILES)

	# This is an example of how to be clever (but still maintainable).
	# We just want the variable BLURRR_USER_SCRIPT_FILES defined.
	# If you have incompatible scripts like using new language features in Lua 5.3 vs. Lua 5.1 (LuaJIT), 
	# then you can conditionalize what gets put into BLURRR_USER_SCRIPT_FILES.

	list(APPEND BLURRR_USER_SCRIPT_FILES_LUA53
		# ${PROJECT_SOURCE_DIR}/scripts/example_native_bitops.lua
		
	)
	list(APPEND BLURRR_USER_SCRIPT_FILES_LUAJIT
		# ${PROJECT_SOURCE_DIR}/scripts/example_jit_control.lua

	)
	list(APPEND BLURRR_USER_SCRIPT_FILES_LUACOMMON
		# mobdebug is often used for Lua debugging such as with ZeroBrane Studio. Uncomment this file for debugging.
		# ${PROJECT_SOURCE_DIR}/scripts/mobdebug.lua

	)
	list(APPEND BLURRR_USER_SCRIPT_FILES_JAVASCRIPT
		# ${PROJECT_SOURCE_DIR}/scripts/exmaple_render_stuff.js

	)

	if(BLURRR_USE_LUA)
		list(APPEND BLURRR_USER_SCRIPT_FILES ${BLURRR_USER_SCRIPT_FILES_LUACOMMON})
		if(BLURRR_USE_LUA53)
			list(APPEND BLURRR_USER_SCRIPT_FILES ${BLURRR_USER_SCRIPT_FILES_LUA53})
		elseif(BLURRR_USE_LUAJIT)
			list(APPEND BLURRR_USER_SCRIPT_FILES ${BLURRR_USER_SCRIPT_FILES_LUAJIT})
		endif()
	elseif(BLURRR_USE_JAVASCRIPT)
		list(APPEND BLURRR_USER_SCRIPT_FILES ${BLURRR_USER_SCRIPT_FILES_JAVASCRIPT})
	endif()


else()
	# We will automatically slurp everything.
	# But you must remember to regenerate every time you add a file.
	set(BLURRR_AUTOMATIC_USER_SCRIPT_FILES_SHOULD_FOLLOW_SYMLINKS TRUE)
	set(BLURRR_AUTOMATIC_USER_SCRIPT_FILES_GLOB_PATTERN "${PROJECT_SOURCE_DIR}/scripts/*")
endif()


if(BLURRR_USE_SWIFT)
	# Add your Swift files here
	list(APPEND BLURRR_USER_SWIFT_COMPILED_FILES
		# This is BlurrrMain.swift, main.swift if applicable, and anything else needed.
		${BLURRR_CORE_SWIFT_SOURCE_MAIN}
	)

	# This is temporary. For now, we put the bindings directly as source 
	# in the project since these are evolving.
	# Eventually when these stabilize, we'll move these into prebuilt modules. 
	list(APPEND BLURRR_USER_COMPILED_FILES
		${BLURRR_CORE_SOURCE_SWIFT_BINDINGS}
	)

endif()

# Add your C/C++/Obj-C files here
list(APPEND BLURRR_USER_COMPILED_FILES
	# This is main_c.c or main_lua.c or main_JavaScriptCore.c
	${BLURRR_CORE_SOURCE_MAIN}
#	${PROJECT_SOURCE_DIR}/source/myfile.c	

)

# Add your C/C++/Obj-C include paths here
list(APPEND BLURRR_USER_INCLUDE_PATHS
	${PROJECT_SOURCE_DIR}/source
)


# Add your find_package() stuff here as needed, 
# then set BLURRR_USER_LIBRARIES and BLURRR_USER_THIRD_PARTY_LIBRARIES_TO_EMBED
list(APPEND BLURRR_USER_LIBRARIES

)

# Remember that system libraries and static libraries don't need to be embedded.
list(APPEND BLURRR_USER_THIRD_PARTY_LIBRARIES_TO_EMBED

)


