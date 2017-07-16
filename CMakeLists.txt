cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(lispish)

# This gets rid of the warning you would have seen earlier if you were using Cygwin. If you aren’t using Cygwin then it has no effect at all.
# This tells CMake not to define WIN32 when building with Cygwin. This is the preferred option and for us it doesn’t make a difference either way so we will use the recommended setting.
set(CMAKE_LEGACY_CYGWIN_WIN32 0)


add_executable(lispish main.cc)
