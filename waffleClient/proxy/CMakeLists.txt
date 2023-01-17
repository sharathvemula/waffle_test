set(PROXY_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(STORAGE_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/../libstorage/src")
set(SERVICE_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/../service/src)

message(STATUS "Inside proxy/CmakeLists.txt include cmake_current_src_dir is : ${STORAGE_INCLUDE}")
include_directories(${PROXY_INCLUDE} ${STORAGE_INCLUDE} ${SERVICE_INCLUDE} "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/libstorage/src")