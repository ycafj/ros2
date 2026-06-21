cmake_minimum_required(VERSION 3.8)
project(angle_srvcli)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(custom_interfaces REQUIRED)
find_package(turtlesim REQUIRED)
find_package(pluginlib REQUIRED)
find_package(polygon_base REQUIRED)
add_library(server_angle SHARED src/angle_server.cpp)
ament_target_dependencies(server_angle rclcpp custom_interfaces turtlesim pluginlib polygon_base rclcpp_components)
rclcpp_components_register_node(
  server_angle
  PLUGIN "angle_srvcli::AngleServer"
  EXECUTABLE angle_server
)
install(TARGETS
  server_angle
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  )

add_executable(angle_client src/angle_client.cpp)
ament_target_dependencies(angle_client rclcpp custom_interfaces)


install(TARGETS
    angle_client
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
