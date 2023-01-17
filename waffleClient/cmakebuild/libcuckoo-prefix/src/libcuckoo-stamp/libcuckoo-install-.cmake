

set(command "${make};install")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp/libcuckoo-install-out.log"
  ERROR_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp/libcuckoo-install-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp/libcuckoo-install-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "libcuckoo install command succeeded.  See also /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp/libcuckoo-install-*.log")
  message(STATUS "${msg}")
endif()
