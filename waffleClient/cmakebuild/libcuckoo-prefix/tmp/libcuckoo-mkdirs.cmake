# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/svemula/Desktop/Downloads/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo"
  "/Users/svemula/Desktop/Downloads/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-build"
  "/Users/svemula/Desktop/Downloads/waffleClient/cmakebuild/libcuckoo-prefix"
  "/Users/svemula/Desktop/Downloads/waffleClient/cmakebuild/libcuckoo-prefix/tmp"
  "/Users/svemula/Desktop/Downloads/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp"
  "/Users/svemula/Desktop/Downloads/waffleClient/cmakebuild/libcuckoo-prefix/src"
  "/Users/svemula/Desktop/Downloads/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/svemula/Desktop/Downloads/waffleClient/cmakebuild/libcuckoo-prefix/src/libcuckoo-stamp/${subDir}")
endforeach()
