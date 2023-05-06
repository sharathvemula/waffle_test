#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "event" for configuration "Release"
set_property(TARGET event APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(event PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/libevent.a"
  )

list(APPEND _cmake_import_check_targets event )
list(APPEND _cmake_import_check_files_for_event "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/libevent.a" )

# Import target "event_core" for configuration "Release"
set_property(TARGET event_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(event_core PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/libevent_core.a"
  )

list(APPEND _cmake_import_check_targets event_core )
list(APPEND _cmake_import_check_files_for_event_core "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/libevent_core.a" )

# Import target "event_extra" for configuration "Release"
set_property(TARGET event_extra APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(event_extra PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/libevent_extra.a"
  )

list(APPEND _cmake_import_check_targets event_extra )
list(APPEND _cmake_import_check_files_for_event_extra "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/libevent_extra.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
