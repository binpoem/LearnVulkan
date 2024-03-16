cmake_minimum_required(VERSION 3.22)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

project(LearnVulkan LANGUAGES C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # 输出commpile_commands.json，用于clangd

# Use FindVulkan module added with CMAKE 3.7
if (NOT CMAKE_VERSION VERSION_LESS 3.7.0)
	message(STATUS "Using module to find Vulkan")
	find_package(Vulkan)
endif()

IF(WIN32)
	# Nothing here (yet)
ELSEIF(APPLE)
	link_libraries(${Vulkan_LIBRARY} "-framework AppKit" "-framework QuartzCore")
ELSE(WIN32)
	link_libraries(${XCB_LIBRARIES} ${Vulkan_LIBRARY} ${Vulkan_LIBRARY} ${DIRECTFB_LIBRARIES} ${WAYLAND_CLIENT_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
ENDIF(WIN32)

include_directories(samples)
add_subdirectory(samples)

include_directories(deps)
add_subdirectory(deps)