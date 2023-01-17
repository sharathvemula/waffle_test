

set(command "/usr/bin/cmake;-Dmake=${make};-Dconfig=${config};-P;/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/openssl_ep-prefix/src/openssl_ep-stamp/openssl_ep-download--impl.cmake")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/openssl_ep-prefix/src/openssl_ep-stamp/openssl_ep-download-out.log"
  ERROR_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/openssl_ep-prefix/src/openssl_ep-stamp/openssl_ep-download-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/openssl_ep-prefix/src/openssl_ep-stamp/openssl_ep-download-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "openssl_ep download command succeeded.  See also /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/openssl_ep-prefix/src/openssl_ep-stamp/openssl_ep-download-*.log")
  message(STATUS "${msg}")
endif()
