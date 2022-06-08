
project(stenography)

add_subdirectory(ThirdParty/zlib EXCLUDE_FROM_ALL)

# libpng requires ZLIB_INCLUDE_DIRS to be defined
set(ZLIB_INCLUDE_DIRS 
    ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/zlib
    ${CMAKE_CURRENT_BINARY_DIR}/ThirdParty/zlib
)

# libpng configurable options

set(PNG_SHARED OFF CACHE BOOL "" FORCE)
set(PNG_STATIC ON CACHE BOOL "" FORCE)
set(PNG_EXECUTABLES OFF CACHE BOOL "" FORCE) # we only want lib
set(PNG_TESTS OFF CACHE BOOL "" FORCE) # we only want lib
set(SKIP_INSTALL_ALL OFF CACHE BOOL "" FORCE) # we only want lib
set(PNG_BUILD_ZLIB ON CACHE BOOL "" FORCE)

add_subdirectory(ThirdParty/libpng EXCLUDE_FROM_ALL)

# generated files from libpng during build
include_directories(${CMAKE_CURRENT_BINARY_DIR}/libpng)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/zlib
    ${CMAKE_CURRENT_BINARY_DIR}/ThirdParty/zlib
    ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/libpng
    ${CMAKE_CURRENT_BINARY_DIR}/ThirdParty/libpng
)

set(SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
add_dependencies(${PROJECT_NAME} png_static zlibstatic)
target_link_libraries(${PROJECT_NAME} png_static zlibstatic)
