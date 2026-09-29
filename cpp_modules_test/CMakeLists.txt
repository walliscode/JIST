
add_library(uses_std )

# Add sources.
target_sources(uses_std
  PRIVATE
    FILE_SET source_files
    TYPE SOURCES
    FILES
      uses_std.cxx
    FILE_SET moduile_files
    TYPE CXX_MODULES
    FILES
      repeat.cppm)
# Tell CMake we're using C++23 but only C++20 is needed to consume it.
target_compile_features(uses_std
  PRIVATE   cxx_std_23
  INTERFACE cxx_std_20)

# Make an executable.
add_executable(main)
# Note that this source is *not* allowed to `import std` as it ends up
# with only C++20 support due to the `uses_std` INTERFACE requirements.
target_sources(main
  PRIVATE
    main.cxx)
target_link_libraries(main PRIVATE uses_std)

