
if(NOT "/tmp/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp/libcuckoo-gitinfo.txt" IS_NEWER_THAN "/tmp/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp/libcuckoo-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/tmp/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp/libcuckoo-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/tmp/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/tmp/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout --config "advice.detachedHead=false" "https://github.com/efficient/libcuckoo.git" "libcuckoo"
    WORKING_DIRECTORY "/tmp/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/efficient/libcuckoo.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout 8785773896d74f72b6224e59d37f5f8c3c1e022a --
  WORKING_DIRECTORY "/tmp/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: '8785773896d74f72b6224e59d37f5f8c3c1e022a'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/tmp/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/tmp/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/tmp/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp/libcuckoo-gitinfo.txt"
    "/tmp/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp/libcuckoo-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/tmp/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp/libcuckoo-gitclone-lastrun.txt'")
endif()

