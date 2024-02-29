CMAKE_MINIMUM_REQUIRED(VERSION 3.25)
PROJECT(packet-detection VERSION 1.0.0)

SET(CMAKE_CXX_STANDARD 17)
SET(binary_target packet-detection)

LIST(APPEND CMAKE_PREFIX_PATH /data/Environment/SharedLib/libtorch)

# all public header for all source files
INCLUDE_DIRECTORIES(
        ${TORCH_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/vendor/spdlog/include
)

#@formatter:off
AUX_SOURCE_DIRECTORY(src                ALL_SOURCES)
AUX_SOURCE_DIRECTORY(src/io             ALL_SOURCES)
AUX_SOURCE_DIRECTORY(src/packet         ALL_SOURCES)
AUX_SOURCE_DIRECTORY(src/callback       ALL_SOURCES)
AUX_SOURCE_DIRECTORY(src/packet/header  ALL_SOURCES)
#@formatter:on

#foreach (file ${ALL_SOURCES})
#    message(STATUS "adding source file ${file} to ${binary_target}")
#endforeach ()

ADD_EXECUTABLE(${binary_target} ${ALL_SOURCES})

# Libtorch
FIND_PACKAGE(Torch REQUIRED)
MESSAGE(STATUS "Torch Libraries: ${TORCH_LIBRARIES}")
MESSAGE(STATUS "Torch Includes: ${TORCH_INCLUDE_DIRS}")

#target_link_libraries(${binary_target} PRIVATE io)
#target_link_libraries(${binary_target} PRIVATE packet)
TARGET_LINK_LIBRARIES(${binary_target} PRIVATE librdkafka++.so)
TARGET_LINK_LIBRARIES(${binary_target} PRIVATE libpcap.so.1.10.4)
TARGET_LINK_LIBRARIES(${binary_target} PRIVATE ${TORCH_LIBRARIES})