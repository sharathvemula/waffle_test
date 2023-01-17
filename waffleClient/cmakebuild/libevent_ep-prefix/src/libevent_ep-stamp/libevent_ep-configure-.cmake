

set(command "/usr/bin/cmake;-Wno-dev;-DCMAKE_CXX_COMPILER=/usr/bin/c++;-DCMAKE_C_COMPILER=/usr/bin/cc;-DCMAKE_INSTALL_PREFIX=/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/external/libevent_ep;-DENABLE_TESTING=OFF;-DBUILD_SHARED_LIBS=OFF;-DEVENT__DISABLE_OPENSSL=ON;-DEVENT__DISABLE_BENCHMARK=ON;-DEVENT__DISABLE_TESTS=ON;-GUnix Makefiles;/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-stamp/libevent_ep-configure-out.log"
  ERROR_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-stamp/libevent_ep-configure-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-stamp/libevent_ep-configure-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "libevent_ep configure command succeeded.  See also /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-stamp/libevent_ep-configure-*.log")
  message(STATUS "${msg}")
endif()
