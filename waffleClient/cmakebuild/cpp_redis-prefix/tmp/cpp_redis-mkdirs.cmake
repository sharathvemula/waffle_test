# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/svemula/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix/src/cpp_redis"
  "/home/svemula/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix/src/cpp_redis-build"
  "/home/svemula/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix"
  "/home/svemula/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix/tmp"
  "/home/svemula/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix/src/cpp_redis-stamp"
  "/home/svemula/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix/src"
  "/home/svemula/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix/src/cpp_redis-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/svemula/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix/src/cpp_redis-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/svemula/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix/src/cpp_redis-stamp${cfgdir}") # cfgdir has leading slash
endif()
