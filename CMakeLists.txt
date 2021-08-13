cmake_minimum_required(VERSION 3.2)

PROJECT(dmenumerate)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()
ModuleSetWinCompilerFlags()

SET(DMENUMERATE_VERSION_MAJOR "1")
SET(DMENUMERATE_VERSION_MINOR "0")
SET(DMENUMERATE_VERSION_PATCH "1")
SET(DMENUMERATE_VERSION "${DMENUMERATE_VERSION_MAJOR}.${DMENUMERATE_VERSION_MINOR}.${DMENUMERATE_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${DMENUMERATE_VERSION}")

OPTION(USE_DMENUMERATE "use dmenumerate" OFF)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/include/dmenumerate_config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/dmenumerate_config.h)
ModuleImport("dmtest" "thirdparty/dmtest")
ModuleImport("dmformat" "thirdparty/dmformat")
LibImport("dmenumerate_module" "src/dmenumerate_module")
ExeImport("test" "dmenumerate_module;dmtest")

#ADD_CUSTOM_COMMAND(
#TARGET dmenumeratetest
#PRE_BUILD
#COMMAND ${CMAKE_COMMAND} -E copy_if_different
#${CMAKE_CURRENT_SOURCE_DIR}/config/test.csv
#$<TARGET_FILE_DIR:dmenumeratetest>
#)

#INSTALL(DIRECTORY include/ DESTINATION include)
#INSTALL(TARGETS dmenumerate
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib)

#SET(DMENUMERATE_LIBS "dmenumerate")
#MARK_AS_ADVANCED(${DMENUMERATE_LIBS})