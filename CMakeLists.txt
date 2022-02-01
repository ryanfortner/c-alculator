cmake_minimum_required(VERSION 3.16)

project(c-alculator VERSION 0.0.1)

add_executable(c-alculator src/main.c)

#install target
install(
	TARGETS c-alculator
	DESTINATION /usr/local/bin
)

# uninstall target
if(NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

  add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()