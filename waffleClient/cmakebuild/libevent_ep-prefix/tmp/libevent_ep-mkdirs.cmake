# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/svemula/Desktop/Downloads/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep"
  "/Users/svemula/Desktop/Downloads/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-build"
  "/Users/svemula/Desktop/Downloads/waffleClient/cmakebuild/libevent_ep-prefix"
  "/Users/svemula/Desktop/Downloads/waffleClient/cmakebuild/libevent_ep-prefix/tmp"
  "/Users/svemula/Desktop/Downloads/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-stamp"
  "/Users/svemula/Desktop/Downloads/waffleClient/cmakebuild/libevent_ep-prefix/src"
  "/Users/svemula/Desktop/Downloads/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/svemula/Desktop/Downloads/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-stamp/${subDir}")
endforeach()
