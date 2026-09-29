# Using modules

This is (currently) some fairly unstructured thoughts on using modules in C++
from own experiences.

## CMake

### referencing files for target

use the target_sources along with FILE_SET to reference the files for a target.
This is useful when you have a module interface file and its implementation
file.

```cmake
target_sources(my_target
    FILE_SET my_module_files
    TYPE CXX_MODULES
    BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
        my_module.ixx
        my_module.cpp
)
```
