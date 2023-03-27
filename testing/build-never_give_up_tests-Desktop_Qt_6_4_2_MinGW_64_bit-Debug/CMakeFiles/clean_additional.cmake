# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\sessionTests_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\sessionTests_autogen.dir\\ParseCache.txt"
  "sessionTests_autogen"
  )
endif()
