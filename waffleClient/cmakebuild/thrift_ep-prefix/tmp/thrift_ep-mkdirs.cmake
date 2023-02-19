# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep"
  "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep-build"
  "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix"
  "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/tmp"
  "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep-stamp"
  "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src"
  "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/svemula/Waffle/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep-stamp${cfgdir}") # cfgdir has leading slash
endif()
