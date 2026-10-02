
cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

# Set experimental flag to enable `import std` support from CMake.
# This must be enabled before C++ language support.
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD
  # This specific value changes as experimental support evolves. See
  # `Help/dev/experimental.rst` in the CMake source corresponding to
  # your CMake build for the exact value to use.

  # Note from Ben Wallis. For some reason i had to to use the value
  # from the v4.4.3 release of CMake.
  # I did not test others apart form v3.30.
  # This is possibly because i have v4.4.3 installed
  # and because we have set minimum it is calling 3.30
  "f35a9ac6-8463-4d38-8eec-5d6008153e7d")

# Tell CMake that we explicitly want `import std`. This will initialize the
# property on all targets declared after this to 1
set(CMAKE_CXX_MODULE_STD 1)

project(
  JIST
  VERSION 0.0.1
  LANGUAGES CXX)

enable_testing()

# This next bit of code comes from Professional CMake: A Practical Guide,
# pg 205 (in documentation/textbooks) as a safe way to add CXX standards
# Require C++23 for CMAKE modules support,
# but let a parent project ask for something higher
if(DEFINED CMAKE_CXX_STANDARD)
  if(CMAKE_CXX_STANDARD MATCHES "^(90|99)$" OR CMAKE_CXX_STANDARD LESS 23)
    message(FATAL_ERROR "This project requires at least C++23")
  endif()
else()
  set(CMAKE_CXX_STANDARD 23)
endif()

# Always enforce the language constraint
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# set the cmake module path (for import libraries and other cmake files)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/fetch-content-modules")

# fetch_content_modules.cmake contains a menu list of all fetch content
# scripts to include. to keep top level cmake tidier
include(fetch-content-modules)

# add_subdirectory(config)
add_subdirectory(src)
# add_subdirectory(tests)
#
#
add_subdirectory(cpp_modules_test)



