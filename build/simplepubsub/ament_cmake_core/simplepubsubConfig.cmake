# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_simplepubsub_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED simplepubsub_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(simplepubsub_FOUND FALSE)
  elseif(NOT simplepubsub_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(simplepubsub_FOUND FALSE)
  endif()
  return()
endif()
set(_simplepubsub_CONFIG_INCLUDED TRUE)

# output package information
if(NOT simplepubsub_FIND_QUIETLY)
  message(STATUS "Found simplepubsub: 0.0.0 (${simplepubsub_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'simplepubsub' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT simplepubsub_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(simplepubsub_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${simplepubsub_DIR}/${_extra}")
endforeach()
