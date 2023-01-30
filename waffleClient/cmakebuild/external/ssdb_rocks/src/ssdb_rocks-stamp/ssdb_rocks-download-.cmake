

set(command "/usr/bin/cmake;-P;/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/external/ssdb_rocks/tmp/ssdb_rocks-gitclone.cmake")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/external/ssdb_rocks/src/ssdb_rocks-stamp/ssdb_rocks-download-out.log"
  ERROR_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/external/ssdb_rocks/src/ssdb_rocks-stamp/ssdb_rocks-download-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/external/ssdb_rocks/src/ssdb_rocks-stamp/ssdb_rocks-download-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "ssdb_rocks download command succeeded.  See also /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/external/ssdb_rocks/src/ssdb_rocks-stamp/ssdb_rocks-download-*.log")
  message(STATUS "${msg}")
endif()