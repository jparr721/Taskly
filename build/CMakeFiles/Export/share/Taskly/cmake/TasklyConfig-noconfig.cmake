#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Taskly" for configuration ""
set_property(TARGET Taskly APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(Taskly PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/Taskly"
  )

list(APPEND _IMPORT_CHECK_TARGETS Taskly )
list(APPEND _IMPORT_CHECK_FILES_FOR_Taskly "${_IMPORT_PREFIX}/bin/Taskly" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
