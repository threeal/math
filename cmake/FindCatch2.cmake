if(Catch2_FOUND)
  return()
endif()

Include(FetchContent)
FetchContent_Declare(Catch2 GIT_REPOSITORY https://github.com/catchorg/Catch2.git GIT_TAG v3.2.0)
FetchContent_MakeAvailable(Catch2)

set(CMAKE_MODULE_PATH "${Catch2_SOURCE_DIR}/extras;${CMAKE_MODULE_PATH}")
include(Catch)
