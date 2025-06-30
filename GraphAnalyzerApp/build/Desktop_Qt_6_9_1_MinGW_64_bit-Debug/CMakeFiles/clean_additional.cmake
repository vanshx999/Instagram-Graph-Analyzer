# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\GraphAnalyzerApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\GraphAnalyzerApp_autogen.dir\\ParseCache.txt"
  "GraphAnalyzerApp_autogen"
  )
endif()
