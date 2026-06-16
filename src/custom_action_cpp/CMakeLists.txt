cmake_minimum_required(VERSION 3.8)
project(custom_action_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(turtlesim REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(pluginlib REQUIRED)
find_package(polygon_base REQUIRED)
find_package(custom_interfaces REQUIRED)
find_package(custom_action_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(rosidl_typesupport_c REQUIRED)
find_package(rosidl_typesupport_cpp REQUIRED)

add_library(action_server SHARED
  src/hunting_action_server.cpp)
target_include_directories(action_server PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_definitions(action_server
  PRIVATE "CUSTOM_ACTION_CPP_BUILDING_DLL")
ament_target_dependencies(action_server
  "custom_action_interfaces"
  "rclcpp"
  "rclcpp_action"
  "rclcpp_components"
  "turtlesim"
  "custom_interfaces"
  "geometry_msgs"
  "pluginlib"
  "polygon_base"
  )

rclcpp_components_register_node(action_server 
  PLUGIN "custom_action_cpp::HuntingActionServer" 
  EXECUTABLE hunting_action_server)

install(TARGETS
  action_server
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

add_library(action_client SHARED
  src/hunting_action_client.cpp)
target_include_directories(action_client PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_definitions(action_client
  PRIVATE "CUSTOM_ACTION_CPP_BUILDING_DLL")
ament_target_dependencies(action_client
  "custom_action_interfaces"
  "rclcpp"
  "rclcpp_action"
  "rclcpp_components")

rclcpp_components_register_node(action_client 
  PLUGIN "custom_action_cpp::HuntingActionClient" 
  EXECUTABLE hunting_action_client)

install(TARGETS
  action_client
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()