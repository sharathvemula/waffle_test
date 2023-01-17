

set(command "${make}")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/external/ssdb_rocks/src/ssdb_rocks-stamp/ssdb_rocks-build-out.log"
  ERROR_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/external/ssdb_rocks/src/ssdb_rocks-stamp/ssdb_rocks-build-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/external/ssdb_rocks/src/ssdb_rocks-stamp/ssdb_rocks-build-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "ssdb_rocks build command succeeded.  See also /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/external/ssdb_rocks/src/ssdb_rocks-stamp/ssdb_rocks-build-*.log")
  message(STATUS "${msg}")
endif()
