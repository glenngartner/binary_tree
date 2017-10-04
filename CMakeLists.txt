cmake_minimum_required(VERSION 3.8)
project(binary_tree)

# configure GLFW subdirectory
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/glfw)

include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/lib/glfw/include ${PROJECT_SOURCE_DIR}/lib/glad/include ${PROJECT_SOURCE_DIR}/lib/glm)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/GL_Renderer.cpp include/GL_Renderer.h src/Node.cpp include/Node.h src/Tree.cpp include/Tree.h src/BasicApp.cpp include/BasicApp.h)
add_executable(binary_tree ${SOURCE_FILES} ${PROJECT_SOURCE_DIR}/lib/glad/src/glad.c)

target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES} ${GLAD_LIBRARIES})