

set(command "/usr/bin/cmake;-Wno-dev;-DCMAKE_CXX_COMPILER=/usr/bin/c++;-DCMAKE_C_COMPILER=/usr/bin/cc;-DCMAKE_BUILD_TYPE=;-DCMAKE_INSTALL_PREFIX=/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/external/thrift_ep;-DCMAKE_INSTALL_RPATH=/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/external/thrift_ep/lib;-DBUILD_COMPILER=;-DBUILD_TESTING=OFF;-DWITH_SHARED_LIB=OFF;-DWITH_QT4=OFF;-DWITH_QT5=OFF;-DWITH_C_GLIB=OFF;-DWITH_HASKELL=OFF;-DWITH_LIBEVENT=ON;-DWITH_ZLIB=OFF;-DWITH_JAVA=OFF;-DWITH_PYTHON=OFF;-DWITH_CPP=ON;-DWITH_STDTHREADS=OFF;-DWITH_BOOSTTHREADS=OFF;-DWITH_STATIC_LIB=ON;-DCMAKE_PREFIX_PATH=\;/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/external/boost_ep\;/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/external/libevent_ep;-GUnix Makefiles;/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep-stamp/thrift_ep-configure-out.log"
  ERROR_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep-stamp/thrift_ep-configure-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep-stamp/thrift_ep-configure-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "thrift_ep configure command succeeded.  See also /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep-stamp/thrift_ep-configure-*.log")
  message(STATUS "${msg}")
endif()
