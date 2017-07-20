cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(lispish)

# Use C++ 14
set(CMAKE_CXX_STANDARD 14)
# This gets rid of the warning you would have seen earlier if you were using Cygwin. If you aren’t using Cygwin then it has no effect at all.
# This tells CMake not to define WIN32 when building with Cygwin. This is the preferred option and for us it doesn’t make a difference either way so we will use the recommended setting.
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(/usr/include/readline)
find_package(Boost)

add_subdirectory(lexer)
add_subdirectory(parser)

file(GLOB SOURCES "*.cc")

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(lispish ${SOURCES})
    target_link_libraries(lispish lispish_lexer lispish_parser readline ${Boost_LIBRARIES})
endif()
