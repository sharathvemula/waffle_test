

set(command "${make};install")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-stamp/libevent_ep-install-out.log"
  ERROR_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-stamp/libevent_ep-install-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-stamp/libevent_ep-install-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "libevent_ep install command succeeded.  See also /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-stamp/libevent_ep-install-*.log")
  message(STATUS "${msg}")
endif()
