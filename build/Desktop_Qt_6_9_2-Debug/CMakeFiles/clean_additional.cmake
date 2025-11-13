# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/projekt_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/projekt_autogen.dir/ParseCache.txt"
  "projekt_autogen"
  )
endif()
