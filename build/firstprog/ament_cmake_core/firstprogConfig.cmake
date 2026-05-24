# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_firstprog_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED firstprog_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(firstprog_FOUND FALSE)
  elseif(NOT firstprog_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(firstprog_FOUND FALSE)
  endif()
  return()
endif()
set(_firstprog_CONFIG_INCLUDED TRUE)

# output package information
if(NOT firstprog_FIND_QUIETLY)
  message(STATUS "Found firstprog: 0.0.0 (${firstprog_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'firstprog' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT firstprog_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(firstprog_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${firstprog_DIR}/${_extra}")
endforeach()
