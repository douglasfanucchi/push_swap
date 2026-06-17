cmake_minimum_required(VERSION 3.14)
project(push_swap_tests)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/add971c.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  tests
  entry.cc
)
target_compile_options(tests PRIVATE -fsanitize=address -g -O1 -fno-omit-frame-pointer -fsanitize=undefined)
target_link_libraries(
  tests
  GTest::gtest_main
)
target_link_libraries(
  tests
  ${CMAKE_SOURCE_DIR}/../libft/libft.a
	${CMAKE_SOURCE_DIR}/../tests.a
)
target_include_directories(
  tests
  PUBLIC
  ${CMAKE_SOURCE_DIR}/../libft/includes
  ${CMAKE_SOURCE_DIR}/..
)
target_link_options(tests PRIVATE -fsanitize=address -g -O1 -fno-omit-frame-pointer -fsanitize=undefined)

include(GoogleTest)
gtest_discover_tests(tests)
