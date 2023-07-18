set(STORAGE_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/../libstorage/src)
set(PROXY_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/../proxy/src)
set(SERVICE_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/../service/src)
set(SERVER_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories(${STORAGE_INCLUDE} ${PROXY_INCLUDE} ${SERVICE_INCLUDE} ${SERVER_INCLUDE})


add_executable(proxy_server
        src/proxy_server.cpp

        ../service/src/thrift_server.cpp
        ../service/src/thrift_server.h
        ../service/src/thrift_handler_factory.cpp
        ../service/src/thrift_handler_factory.h
        ../service/src/thrift_handler.cpp
        ../service/src/thrift_handler.h
        ../service/src/thrift_response_client_map.cpp
        ../service/src/thrift_response_client_map.h
        ../service/src/thrift_response_client.cpp
        ../service/src/thrift_response_client.h
        ../service/src/waffle_thrift_response.cpp
        ../service/src/waffle_thrift_response.h
        ../service/src/waffle_thrift.cpp
        ../service/src/waffle_thrift.h
        ../service/src/proxy_types.cpp
        ../service/src/proxy_types.h

        ../proxy/src/waffle_proxy.cpp
        ../proxy/src/waffle_proxy.h
        ../proxy/src/proxy.h
        ../proxy/src/operation.h
        ../proxy/src/queue.h
        ../proxy/src/util.h
        ../proxy/src/util.cpp
        ../proxy/src/Cache.cpp
        ../proxy/src/Cache.hpp
        ../proxy/src/FrequencySmoother.cpp
        ../proxy/src/FrequencySmoother.hpp
        ../proxy/src/encryption_engine.cpp
        ../proxy/src/encryption_engine.h
        ../proxy/src/ThreadSafeUnorderedMap.h
        ../proxy/src/evictedItems.cpp
        ../proxy/src/evictedItems.h
        


        ../libstorage/src/storage_interface.h
        ../libstorage/src/redis.h
        ../libstorage/src/redis.cpp

        ../service/src/thrift_utils.h)
add_dependencies(proxy_server libcuckoo thrift_ep)
target_link_libraries(proxy_server
        Threads::Threads
        ${THRIFTNB_LIBRARY}
        ${THRIFT_LIBRARY}
        ${LIBEVENT_LIBRARY}
        ${CPP_REDIS_LIBRARIES}
        ${OPENSSL_LIBRARIES}
        ${SSDB_CLIENT_LIBRARY}
        ${LEVELDB_LIBRARY}
        ${SNAPPY_LIBRARY}
        ${JEMALLOC_LIBRARY}
        ${CMAKE_DL_LIBS}
        ${ZLIB_LIBRARIES}
        ${BZIP2_LIBRARIES}
        #${LIBMEMCACHED_LIBRARIES}
        ${PROXY_INCLUDE_LIBRARIES}
        ${STORAGE_INCLUDE_LIBRARIES}
        ${BENCHMARK_INCLUDE_LIBRARIES}
        ${SERVICE_INCLUDE_LIBRARIES}
        ${CLIENT_INCLUDE_LIBRARIES}
        Threads::Threads)
