set(PROXY_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/../proxy/src)
set(SERVICE_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/../service/src)
set(SERVER_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories(${PROXY_INCLUDE} ${SERVICE_INCLUDE} ${SERVER_INCLUDE} )


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

        ../service/src/thrift_utils.h)
add_dependencies(proxy_server libcuckoo thrift_ep)
target_link_libraries(proxy_server
        Threads::Threads
        ${THRIFTNB_LIBRARY}
        ${THRIFT_LIBRARY}
        #${LIBMEMCACHED_LIBRARIES}
        ${PROXY_INCLUDE_LIBRARIES}
        ${BENCHMARK_INCLUDE_LIBRARIES}
        ${SERVICE_INCLUDE_LIBRARIES}
        ${CLIENT_INCLUDE_LIBRARIES}
        Threads::Threads)