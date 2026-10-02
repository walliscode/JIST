add_library(data)

target_sources(data
  PRIVATE
    FILE_SET source_files
    TYPE SOURCES
    FILES
  PUBLIC
    FILE_SET module_files
    TYPE CXX_MODULES
    FILES
      data.cppm
      models.cppm
)
