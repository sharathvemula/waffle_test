

set(command "./config;-fPIC;--prefix=/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/external/openssl;no-comp;no-shared;no-tests;CXX=/usr/bin/c++;CC=/usr/bin/cc")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/openssl_ep-prefix/src/openssl_ep-stamp/openssl_ep-configure-out.log"
  ERROR_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/openssl_ep-prefix/src/openssl_ep-stamp/openssl_ep-configure-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/openssl_ep-prefix/src/openssl_ep-stamp/openssl_ep-configure-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "openssl_ep configure command succeeded.  See also /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/openssl_ep-prefix/src/openssl_ep-stamp/openssl_ep-configure-*.log")
  message(STATUS "${msg}")
endif()
