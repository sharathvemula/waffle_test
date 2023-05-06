# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/svemula/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo"
  "/home/svemula/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-build"
  "/home/svemula/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix"
  "/home/svemula/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/tmp"
  "/home/svemula/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp"
  "/home/svemula/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src"
  "/home/svemula/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/svemula/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/svemula/waffle_test/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp${cfgdir}") # cfgdir has leading slash
endif()
