

set(command "/usr/bin/cmake;-Wno-dev;-DCMAKE_CXX_COMPILER=/usr/bin/c++;-DCMAKE_C_COMPILER=/usr/bin/cc;-DCMAKE_CXX_FLAGS=;-DCMAKE_C_FLAGS=;-DCMAKE_BUILD_TYPE=;-DCMAKE_INSTALL_PREFIX=/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/external/libcuckoo;-DBUILD_EXAMPLES=OFF;-DBUILD_TESTS=OFF;-DBUILD_SHARED_LIBS=OFF;-GUnix Makefiles;/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp/libcuckoo-configure-out.log"
  ERROR_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp/libcuckoo-configure-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp/libcuckoo-configure-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "libcuckoo configure command succeeded.  See also /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp/libcuckoo-configure-*.log")
  message(STATUS "${msg}")
endif()
