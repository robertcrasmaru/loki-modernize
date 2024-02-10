cmake_minimum_required(VERSION 3.0.0)
project(Loki-Modernize VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# glob all headers and sources
file(GLOB loki-modernize CONFIGURE_DEPENDS "*.h" "*.cpp")

add_library(Loki-Modernize-Lib SHARED ${loki-modernize})

add_executable(Loki-Modernize Loki-Modernize.cpp )
target_link_libraries(Loki-Modernize Loki-Modernize-Lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
