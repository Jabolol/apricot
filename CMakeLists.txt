cmake_minimum_required(VERSION 3.28)
project(apricot CXX)

add_subdirectory(lib/socketio)

file(GLOB SOURCES "src/*.cpp")

find_package(OpenSSL REQUIRED)
find_package(sioclient CONFIG REQUIRED)

add_executable(apricot ${SOURCES})

target_compile_features(apricot PRIVATE cxx_std_20)
target_link_libraries(apricot PRIVATE sioclient::sioclient sioclient::sioclient_tls)

target_compile_options(apricot PRIVATE -Wall -Werror)
