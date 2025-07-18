# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\arthadrishya_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\arthadrishya_autogen.dir\\ParseCache.txt"
  "arthadrishya_autogen"
  )
endif()
