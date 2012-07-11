find_package(Boost 1.46 REQUIRED)

find_package(Boost COMPONENTS system thread program_options REQUIRED)

include_directories("${PROJECT_SOURCE_DIR}/inc" ${Boost_INCLUDE_DIR})

link_directories(${Boost_LIBRARY_DIR})

add_executable(sevenmile sevenmile.cpp ${PROJECT_SOURCE_DIR}/inc/handshake_message.pb.cc)

target_link_libraries(sevenmile ${Boost_LIBRARIES} protobuf)
