

set(command "./b2;link=static;variant=release;cxxflags=-fPIC;cflags=-fPIC;--prefix=/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/external/boost_ep;--with-program_options;install")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/boost_ep-prefix/src/boost_ep-stamp/boost_ep-build-out.log"
  ERROR_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/boost_ep-prefix/src/boost_ep-stamp/boost_ep-build-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/boost_ep-prefix/src/boost_ep-stamp/boost_ep-build-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "boost_ep build command succeeded.  See also /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/boost_ep-prefix/src/boost_ep-stamp/boost_ep-build-*.log")
  message(STATUS "${msg}")
endif()
