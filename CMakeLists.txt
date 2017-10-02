cmake_minimum_required(VERSION 3.8)
project(binary_tree)

add_subdirectory(${PROJECT_SOURCE_DIR}/lib/Cinder)

include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/lib/Cinder/include)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/AppRenderer.cpp include/AppRenderer.h src/Node.cpp include/Node.h src/Tree.cpp include/Tree.h src/BasicApp.cpp include/BasicApp.h src/NodeGraphic.cpp include/NodeGraphic.h src/TreeGraphic.cpp include/TreeGraphic.h)
add_executable(binary_tree ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} cinder ${CINDER_LIBRARIES})