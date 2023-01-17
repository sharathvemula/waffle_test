

set(command "/usr/bin/cmake;-P;/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix/tmp/cpp_redis-gitclone.cmake")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix/src/cpp_redis-stamp/cpp_redis-download-out.log"
  ERROR_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix/src/cpp_redis-stamp/cpp_redis-download-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix/src/cpp_redis-stamp/cpp_redis-download-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "cpp_redis download command succeeded.  See also /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix/src/cpp_redis-stamp/cpp_redis-download-*.log")
  message(STATUS "${msg}")
endif()
