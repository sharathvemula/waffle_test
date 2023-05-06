# Install script for directory: /home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "lib" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/libevent.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib" TYPE STATIC_LIBRARY FILES "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-build/lib/libevent.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/buffer.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/bufferevent.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/bufferevent_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/bufferevent_struct.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/buffer_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/dns.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/dns_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/dns_struct.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/event.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/event_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/event_struct.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/http.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/http_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/http_struct.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/keyvalq_struct.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/listener.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/rpc.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/rpc_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/rpc_struct.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/tag.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/tag_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/thread.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/util.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/visibility.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/event-config.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2" TYPE FILE FILES
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/buffer.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/bufferevent.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/bufferevent_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/bufferevent_struct.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/buffer_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/dns.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/dns_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/dns_struct.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/event.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/event_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/event_struct.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/http.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/http_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/http_struct.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/keyvalq_struct.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/listener.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/rpc.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/rpc_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/rpc_struct.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/tag.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/tag_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/thread.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/util.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/visibility.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-build/include/event2/event-config.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "lib" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/libevent_core.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib" TYPE STATIC_LIBRARY FILES "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-build/lib/libevent_core.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/buffer.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/bufferevent.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/bufferevent_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/bufferevent_struct.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/buffer_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/dns.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/dns_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/dns_struct.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/event.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/event_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/event_struct.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/http.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/http_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/http_struct.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/keyvalq_struct.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/listener.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/rpc.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/rpc_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/rpc_struct.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/tag.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/tag_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/thread.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/util.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/visibility.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/event-config.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2" TYPE FILE FILES
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/buffer.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/bufferevent.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/bufferevent_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/bufferevent_struct.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/buffer_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/dns.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/dns_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/dns_struct.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/event.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/event_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/event_struct.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/http.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/http_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/http_struct.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/keyvalq_struct.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/listener.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/rpc.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/rpc_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/rpc_struct.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/tag.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/tag_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/thread.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/util.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/visibility.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-build/include/event2/event-config.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "lib" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/libevent_extra.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib" TYPE STATIC_LIBRARY FILES "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-build/lib/libevent_extra.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/buffer.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/bufferevent.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/bufferevent_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/bufferevent_struct.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/buffer_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/dns.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/dns_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/dns_struct.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/event.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/event_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/event_struct.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/http.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/http_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/http_struct.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/keyvalq_struct.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/listener.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/rpc.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/rpc_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/rpc_struct.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/tag.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/tag_compat.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/thread.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/util.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/visibility.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2/event-config.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event2" TYPE FILE FILES
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/buffer.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/bufferevent.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/bufferevent_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/bufferevent_struct.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/buffer_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/dns.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/dns_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/dns_struct.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/event.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/event_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/event_struct.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/http.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/http_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/http_struct.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/keyvalq_struct.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/listener.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/rpc.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/rpc_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/rpc_struct.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/tag.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/tag_compat.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/thread.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/util.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event2/visibility.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-build/include/event2/event-config.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/evdns.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/evrpc.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/event.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/evhttp.h;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include/evutil.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/include" TYPE FILE FILES
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/evdns.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/evrpc.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/event.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/evhttp.h"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep/include/evutil.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/cmake/libevent/LibeventConfig.cmake;/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/cmake/libevent/LibeventConfigVersion.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/cmake/libevent" TYPE FILE FILES
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-build//CMakeFiles/LibeventConfig.cmake"
    "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-build/LibeventConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/cmake/libevent/LibeventTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/cmake/libevent/LibeventTargets.cmake"
         "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-build/CMakeFiles/Export/3144ab487d6abd9120b73c5830d038d1/LibeventTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/cmake/libevent/LibeventTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/cmake/libevent/LibeventTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/cmake/libevent/LibeventTargets.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/cmake/libevent" TYPE FILE FILES "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-build/CMakeFiles/Export/3144ab487d6abd9120b73c5830d038d1/LibeventTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/cmake/libevent/LibeventTargets-release.cmake")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "/home/svemula/waffle_test/waffleClient/cmakebuild/external/libevent_ep/lib/cmake/libevent" TYPE FILE FILES "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-build/CMakeFiles/Export/3144ab487d6abd9120b73c5830d038d1/LibeventTargets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/svemula/waffle_test/waffleClient/cmakebuild/libevent_ep-prefix/src/libevent_ep-build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
