# Install script for directory: /home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo/libcuckoo

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/external/libcuckoo")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/libcuckoo/libcuckoo-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/libcuckoo/libcuckoo-targets.cmake"
         "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-build/libcuckoo/CMakeFiles/Export/75bb23512b5425b712dad2372e5f21bd/libcuckoo-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/libcuckoo/libcuckoo-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/libcuckoo/libcuckoo-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/libcuckoo" TYPE FILE FILES "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-build/libcuckoo/CMakeFiles/Export/75bb23512b5425b712dad2372e5f21bd/libcuckoo-targets.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/libcuckoo" TYPE FILE FILES
    "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo/libcuckoo/libcuckoo-config.cmake"
    "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-build/libcuckoo/libcuckoo-config-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/external/libcuckoo/include/libcuckoo/cuckoohash_config.hh;/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/external/libcuckoo/include/libcuckoo/cuckoohash_map.hh;/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/external/libcuckoo/include/libcuckoo/cuckoohash_util.hh;/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/external/libcuckoo/include/libcuckoo/bucket_container.hh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/external/libcuckoo/include/libcuckoo" TYPE FILE FILES
    "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo/libcuckoo/cuckoohash_config.hh"
    "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo/libcuckoo/cuckoohash_map.hh"
    "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo/libcuckoo/cuckoohash_util.hh"
    "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo/libcuckoo/bucket_container.hh"
    )
endif()

