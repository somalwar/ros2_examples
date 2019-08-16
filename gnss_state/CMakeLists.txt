cmake_minimum_required(VERSION 3.5)
project(gnss_state)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(sensor_msgs REQUIRED)

include_directories(include)

add_library(composition_node SHARED
  src/state_node.cpp)
target_compile_definitions(composition_node
PRIVATE "GNSS_STATE_DLL"
ament_target_dependencies(composition_node rclcpp rclcpp_components std_msgs sensor_msgs))

if(NOT WIN32)
  ament_environment_hooks(
    "${ament_cmake_package_templates_ENVIRONMENT_HOOK_LIBRARY_PATH}"
    )
endif()

add_executable(state_node src/state_node.cpp)
target_link_libraries(state_node composition_node)
ament_target_dependencies(state_node
  rclcpp)

add_executable(standalone_state_node src/standalone_state_node.cpp)
target_link_libraries(standalone_state_node composition_node)
ament_target_dependencies(standalone_state_node rclcpp class_loader)

install(TARGETS
  composition_node
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

install(TARGETS
  state_node
  standalone_state_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
