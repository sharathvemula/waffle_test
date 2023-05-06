# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep"
  "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-build"
  "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix"
  "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/tmp"
  "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-stamp"
  "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src"
  "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-stamp${cfgdir}") # cfgdir has leading slash
endif()
