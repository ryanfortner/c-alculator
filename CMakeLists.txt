cmake_minimum_required(VERSION 3.10)

project(c-alculator VERSION 0.1.0)

add_executable(c-alculator src/main.c)

set(CALC_ROOT ${CMAKE_SOURCE_DIR})

#install target
install(
	TARGETS c-alculator
	DESTINATION /usr/local/bin
)

# uninstall target
if(NOT TARGET uninstall)
  configure_file(
    "${CALC_ROOT}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

  add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Ryan Fortner")
set(CPACK_PACKAGE_CONTACT "ryankfortner@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION "simple calculator written in C")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6")
set(CPACK_PACKAGE_HOMEPAGE_URL, "https://github.com/ryanfortner/c-alculator")
file(STRINGS "${CALC_ROOT}/src/main.c" TEMP_STRING REGEX "CALC_MAJOR\\s*")
string(REGEX REPLACE "CALC_MAJOR" "" TEMP_STRING ${TEMP_STRING})
string(REGEX MATCH "[0-9]" CALC_MAJOR ${TEMP_STRING})
file(STRINGS "${CALC_ROOT}/src/main.c" TEMP_STRING REGEX "CALC_MINOR\\s*")
string(REGEX REPLACE "CALC_MINOR" "" TEMP_STRING ${TEMP_STRING})
string(REGEX MATCH "[0-9]" CALC_MINOR ${TEMP_STRING})
file(STRINGS "${CALC_ROOT}/src/main.c" TEMP_STRING REGEX "CALC_REVISION\\s*")
string(REGEX REPLACE "CALC_REVISION" "" TEMP_STRING ${TEMP_STRING})
string(REGEX MATCH "[0-9]" CALC_REVISION ${TEMP_STRING})
set(CPACK_PACKAGE_VERSION_MAJOR ${CALC_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${CALC_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${CALC_REVISION})
set(CPACK_RESOURCE_FILE_LICENSE "${CALC_ROOT}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CALC_ROOT}/README.md")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
INCLUDE(CPack)
